#include <qapplication.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qwmatrix.h>
#include <qpainter.h>
#include <stdio.h>

#include "dieptemeting.h"

// $Date$
// $Author$
// $Revision$

// Dieptemeting met selectie in QListView
//
// Bij een selectie in het QListView venster
// wordt de selectie van de betrokken driehoek zichtbaar
// in het DVenster venster.

DVenster::DVenster( QWidget *parent, const char *name )
        : QWidget( parent, name )
{
   // hierdoor krijg je ook mouse move events
   // zonder de muisknop ingedrukt
   setMouseTracking(true);

   dmm = NULL;
   dse = NULL;
   
   // bouw alle objecten
   maakvaart();
}



void DVenster::maakvaart()
{
   printf("start\n");

   v = new Vaart();
//   v->leesbestand("OELG_B06.DAT");
   v->leesbestand("DATA.DAT");
   v->maakstroken();
   v->berekenminmax();
//   v->toon();

   maakboom();
}



void DVenster::paintEvent( QPaintEvent * )
{
    QPainter p( this );
   
    // sla de instellingen van de qpainter op
    p.save();
    
    // haal de oorsprong, breedte en hoogte op van het venster
    QRect r = p.viewport();

    // hou viewport bij
    xv = r.left();
    yv = r.top();
    bv = r.width();
    hv = r.height();
    printf("viewport %d %d %d %d\n", xv, yv, bv, hv);

    // haal de oorsprong, breedte en hoogte op van het kanaal
    xk = v->getminx();
    yk = v->getminy();
    bk = v->getmaxx() - v->getminx();
    hk = v->getmaxy() - v->getminy();
    printf("window %lf %lf %lf %lf\n", xk, yk, bk, hk);

    double av = ((double) hv)/bv;
    double ak = (v->getmaxy() - v->getminy())/(v->getmaxx() - v->getminx());
    
    printf("aspectratio's window %lf  kanaal %lf\n", av, ak);
    
    // stel in hoe de rechthoek waarbinnen geteken wordt,
    // zichtbaar wordt in het venster
    // dit is afhankelijk van de aspectratio a=h/b
    if (av > ak)
    {
       b = bv;
       h = (int) (ak * b);
       p.setViewport(xv, yv + (hv - h)/2, b, h);
    }
    else
    {
       h = hv;
       b = (int) (h/ak);
       p.setViewport(xv + (bv - b)/2, yv , b ,h);
    }

    // hiermee stellen we de wereldcoordinaten in    
    p.setWindow((int)xk, (int)yk, (int)bk, (int)hk);


    // haal de min. en max. diepte voor de kleurbepaling  
    double minz = v->getminz();
    double maxz = v->getmaxz();

    // teken het kanaal    
    v->teken(&p, minz, maxz);

    // teken de omuis en selectie opnieuw
    if (dmm != NULL)
    {
       dmm->teken(&p, minz, maxz);
    }
    if (dse != NULL)
    {
       dse->teken(&p, minz, maxz);
    }

    // herstel de instellingen van de qpainter
    p.restore();
}

void DVenster::mouseMoveEvent(QMouseEvent *ev)
{
   int x = ev->x();
   int y = ev->y();
   printf("mm %d %d\n", x, y);

   int xx = (int) ((x - (double)((bv - b)/2.0))/hv*hk + xk);
   int yy = (int) ((y - (double)yv)/hv*hk + yk);
//   printf("ww %d %d\n", xx, yy);
//   printf("window %lf %lf %lf %lf\n", xk, yk, bk, hk);

   if (xx < xk || yy < yk || 
       xx >= xk+bk || yy >= yk+hk)
   {
      printf("buiten\n");
      return;
   } 
   
   // zoek uitdrukking onder muis
   Driehoek *dr = v->zoek(xx, yy);
   
   if (dr != dmm)
   {
      if (dmm != NULL)
      {
         dmm->setomuis(false);
      }
      if (dr != NULL)
      {
         dr->setomuis(true);
      }
      dmm = dr;
      repaint();
   }
}

void DVenster::mousePressEvent(QMouseEvent *ev)
{
   if (dmm != dse)
   {
      if (dse != NULL)
      {
         dse->setomuis(false);
         dse->setselectie(false);
      }
      if (dmm != NULL)
      {
         dmm->setselectie(true);
      }
      dse = dmm;
      repaint();
   }
}



void Vaart::teken(QPainter *qp, double minz, double maxz)
{
   // teken alle stroken
   for (int i=0; i<nstroken; i++)
   {
      stroken[i]->teken(qp, minz, maxz);
   }
}

void Strook::teken(QPainter *qp, double minz, double maxz)
{
   // teken alle driehoeken
   for (int i=0; i<ndriehoeken; i++)
   {
      driehoeken[i]->teken(qp, minz, maxz);
   }
   
}

// teken een driehoek met een vulkleur volgens diepte

void Driehoek::teken(QPainter *qp, double minz, double maxz)
{
   int x1 = (int) p1->x;
   int y1 = (int) p1->y;
   int x2 = (int) p2->x;
   int y2 = (int) p2->y;
   int x3 = (int) p3->x;
   int y3 = (int) p3->y;
   


   // kleur voor de grootste diepte
   int rmax = 0;
   int gmax = 0;
   int bmax = 255;
   
   // kleur voor de kleinste diepte
   int rmin = 0;
   int gmin = 255;
   int bmin = 0;
   
   // bereken gemiddelde diepte
   double z = (p1->z + p2->z + p3->z)/3.0;
   
   // u varieert van 0.0 (min. diepte) tot 1.0 (maximale diepte) 
   double u = (z - minz)/(maxz - minz);

   // dit is de interpolatie   
   int r = int (rmax * u + rmin * (1.0 - u));
   int g = int (gmax * u + gmin * (1.0 - u));
   int b = int (bmax * u + bmin * (1.0 - u));

   // stel de lijnkleur in
   qp->setPen( QColor(r,g,b));
   
   // stel de vulkleur in
   qp->setBrush( QColor(r,g,b));
   
   
   // teken gevulde driehoek
   QPointArray pts;
   pts.setPoints( 3,   x1, y1, x2, y2, x3, y3 );
   qp->drawConvexPolygon( pts );

   if (omuis || selectie)
   {
      if (omuis)
      {
         qp->setPen( QColor(0,0,0));
      }
      else
      {
         qp->setPen( QColor(255,0,0));
      }
         
      // teken lijnen rond driehoek
      qp->drawLine(x1, y1, x2, y2);
      qp->drawLine(x2, y2, x3, y3);
      qp->drawLine(x3, y3, x1, y1);
   }
}

// -------- QListView functies -----------

void DVenster::maakboom()
{
   // Maak een boomvenster
   lv = new QListView();
   
   // Toon een - of + teken
   lv->setRootIsDecorated(true);

   // Toon deze kolommen
   lv->addColumn("naam");
   lv->addColumn("p1 nr");
   lv->addColumn("p2 nr");
   lv->addColumn("p3 nr");

   // Maak alle items
   // Vaart --> Strook --> Driehoek
   v->maakitem(lv);    

   // Je kan slechts een item selecteren
   lv->setSelectionMode( QListView::Single );
   
   // Bij een selectionChanged() signal afkomstig
   // van lv wordt hier slotLVChanged() uitgevoerd.
   // Deze vorm van eventafhandeling is specifiek voor Qt.
   connect( lv, SIGNAL( selectionChanged() ),
            this, SLOT( slotLVChanged() ) );
   lv->show();
}


/*
  Een eigen itemklasse noodzakelijk
  om vanuit een item de betrokken driehoek
  te kunnen bijhouden.
 */

class QListViewDriehoekItem : public QListViewItem
{
public:
   QListViewDriehoekItem(QListViewItem *it, char *naam, char *np1, char *np2, char *np3, Driehoek *dr)
     : QListViewItem(it, naam, np1, np2, np3), drieh(dr)
   {
   }
   Driehoek *getDriehoek()
   {
      return drieh;
   }
   
private:
   Driehoek *drieh;  // de driehoek die bij deze item hoort
};

QListViewItem *Vaart::maakitem(QListView *parent)
{
   QListViewItem *it = new QListViewItem(parent, "vaart");

   for (int i=0; i<nstroken; i++)
   {
      QListViewItem *itk = stroken[i]->maakitem(it);
      it->insertItem(itk);
   }
   return it;
}


QListViewItem *Strook::maakitem(QListViewItem *parent)
{
   QListViewItem *it = new QListViewItem(parent, "Strook");
   for (int i=0; i<ndriehoeken; i++)
   {
      QListViewItem *itk = driehoeken[i]->maakitem(it);
      it->insertItem(itk);
   }
   return it;
}


QListViewItem *Driehoek::maakitem(QListViewItem *parent)
{
   char bn[50];
   char bp1[50];
   char bp2[50];
   char bp3[50];

   sprintf(bn,"Driehoek");
   sprintf(bp1,"%d", p1->nr);
   sprintf(bp2,"%d", p2->nr);
   sprintf(bp3,"%d", p3->nr);
   QListViewItem *it = new QListViewDriehoekItem(parent, bn, bp1, bp2, bp3, this);

   return it;
}


// Deze methode loopt bij een selectie in de boom

void DVenster::slotLVChanged()
{
   printf("slotLVChanged\n");
   
   // Haal de huidige selectie op.
   QListViewItem *it = lv->currentItem();

   // Dit is een dynamic cast. Het resultaat is NULL (mislukt)
   // of niet-NULL (gelukt). Deze cast is noodzakelijk om 
   // aan de driehoek te geraken.
   QListViewDriehoekItem *itd  = dynamic_cast<QListViewDriehoekItem *>(it);
   if (itd != NULL)
   {
      printf("driehoek item\n");
      Driehoek *dr = itd->getDriehoek();
      
      // pas de selectie aan
      if (dr != dse)
      {
         if (dse != NULL)
         {
            dse->setomuis(false);
            dse->setselectie(false);
         }
         if (dr != NULL)
         {
            dr->setselectie(true);
         }
         dse = dr;
         repaint();
      }
   }
   else
   {
      printf("geen driehoek item\n");
   }
}

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    DVenster w;
    w.setGeometry( 100, 100, 400, 300 );
    a.setMainWidget( &w );
    w.show();
    return a.exec();
}





