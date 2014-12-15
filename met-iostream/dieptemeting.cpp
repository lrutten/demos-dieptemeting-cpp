/*
#include <qapplication.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qwmatrix.h>
#include <qpainter.h>
*/

#include <iostream>
#include <QtGui>
#include "vaart.h"
#include "kleurpad.h"

// $Date: 2011-12-14 15:46:31 +0100 (Wed, 14 Dec 2011) $
// $Author: lrutten $
// $Revision: 3040 $

class DVenster : public QWidget
{
public:
    DVenster( QWidget *parent=0);
    void maakvaart();
    
protected:
    void paintEvent( QPaintEvent * );
    void mouseMoveEvent( QMouseEvent * );
    void mousePressEvent( QMouseEvent * );
    
private:
   Vaart *v;
   Driehoek *dmm;
   Driehoek *dse;

   // viewport
   //  de afmetingen van het venster
   //  in venstercoordinaten (pixel)
   int xv;
   int yv;
   int bv;
   int hv;

   // de afmeting van de vaart
   // in venster coordinaten
   int b;
   int h;

   // window
   //  de afmetingen in wereldcoordinaten
   double xk;
   double yk;
   double bk;
   double hk;
};


DVenster::DVenster( QWidget *parent)
        : QWidget( parent)
{
   // setMinimumSize( 200, 120 );
   // setMaximumSize( 200, 120 );

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
   v->leesbestand("OELG_B06.DAT");
//   v->leesbestand("DATA.DAT");
   v->maakstroken();
   v->berekenminmax();
//   v->toon();
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
    cout << "viewport " << xv << " " << yv << " " << bv << " " << hv << "\n";

    // haal de oorsprong, breedte en hoogte op van het kanaal
    xk = v->getminx();
    yk = v->getminy();
    bk = v->getmaxx() - v->getminx();
    hk = v->getmaxy() - v->getminy();
    cout << "window " << xk << " " << yk << " " << bk << " " << hk << "\n";

    double av = ((double) hv)/bv;
    double ak = (v->getmaxy() - v->getminy())/(v->getmaxx() - v->getminx());
    
    cout << "aspectratio's window " << av  << " kanaal " << ak << "\n";
    
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
   cout << "mm " << x << y << "\n";

   int xx = (int) ((x - (double)((bv - b)/2.0))/hv*hk + xk);
   int yy = (int) ((y - (double)yv)/hv*hk + yk);
//   printf("ww %d %d\n", xx, yy);
//   printf("window %lf %lf %lf %lf\n", xk, yk, bk, hk);

   if (xx < xk || yy < yk || 
       xx >= xk+bk || yy >= yk+hk)
   {
      cout << "buiten\n";
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
/*
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

   QPolygon polygon(3);
   polygon.putPoints(0, 3, x1, y1, x2, y2, x3, y3);
   qp->drawPolygon( polygon );

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
*/

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

   KleurPad *kp = new KleurPad();
   kp->voegbij(new Kleur(0.0, rmin, gmin, bmin));
   kp->voegbij(new Kleur(0.4,    0,  255,  255));
   kp->voegbij(new Kleur(0.7,  255,    0,    0));
   kp->voegbij(new Kleur(1.0, rmax, gmax, bmax));
   kp->interpoleer(u);
   int r = kp->getr();
   int g = kp->getg();
   int b = kp->getb();
   delete kp;
   
   // dit is de interpolatie   
   /*
   int r = int (rmax * u + rmin * (1.0 - u));
   int g = int (gmax * u + gmin * (1.0 - u));
   int b = int (bmax * u + bmin * (1.0 - u));
   */
   
   // stel de lijnkleur in
   qp->setPen( QColor(r,g,b));
   
   // stel de vulkleur in
   qp->setBrush( QColor(r,g,b));
   
   
   // teken gevulde driehoek

   QPolygon polygon(3);
   polygon.putPoints(0, 3, x1, y1, x2, y2, x3, y3);
   qp->drawPolygon( polygon );

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



int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    DVenster w;
    w.setGeometry( 100, 100, 800, 600 );
    //a.setMainWidget( &w );
    w.show();
    return a.exec();
}





