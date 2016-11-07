
#include <QtGui>

#include <iostream>
#include "vaart.h"

// 7/11/2016
// L. Rutten

// dieptemeting met QTreeWidget zonder selectie
// De vaart, metingen en punten worden in een boomformaat weergegeven.
// En de dieptelijnen worden getoond.

class DVenster : public QWidget
{
public:
    DVenster( QWidget *parent=0 );
    void maakvaart();
    void maakboom();
    
protected:
    void paintEvent( QPaintEvent * );
    
private:
   Vaart *v;    
};


DVenster::DVenster( QWidget *parent)
        : QWidget( parent)
{
   // setMinimumSize( 200, 120 );
   // setMaximumSize( 200, 120 );

   // bouw alle objecten
   maakvaart();
}


void DVenster::maakboom()
{
   QTreeWidget *lv = new QTreeWidget();
   
   // toon + of - teken
   //lv->setRootIsDecorated(true);

   // Er worden 4 kolommen getoond.
   // De eerste geeft de boom weer.
	QTreeWidgetItem* headerItem = new QTreeWidgetItem();
	headerItem->setText(0,QString("naam"));
	headerItem->setText(1,QString("x"));
	headerItem->setText(2,QString("y"));
	headerItem->setText(3,QString("Z"));
	lv->setHeaderItem(headerItem);

   /*
   lv->addColumn("naam");
   lv->addColumn("x");
   lv->addColumn("y");
   lv->addColumn("z");
   */
   
   // Maak alle items voor de boom.
   v->maakitem(lv);

   lv->show();
}


void DVenster::maakvaart()
{
   printf("start\n");

   v = new Vaart();
   v->leesbestand("OELG_B06.DAT");
   //v->leesbestand("DATA.DAT");
   v->maakstroken();
   v->berekenminmax();
   v->maakdieptelijnen();

   v->toon();

   v->dumpobj("java/diepte.obj");
   maakboom();
}



void DVenster::paintEvent( QPaintEvent * )
{
    QPainter p( this );
   
    // sla de instellingen van de qpainter op
    p.save();
    
    // haal de oorsprong, breedte en hoogte op van het venster
    QRect r = p.viewport();
    int xv = r.left();
    int yv = r.top();
    int bv = r.width();
    int hv = r.height();
    cout << "viewport " << xv << " " << yv << " " << bv << " " << hv << "\n";

    // haal de oorsprong, breedte en hoogte op van het kanaal
    int xk = (int) v->getminx();
    int yk = (int) v->getminy();
    int bk = (int) (v->getmaxx() - v->getminx());
    int hk = (int) (v->getmaxy() - v->getminy());
    cout << "window " << xk << " " << yk << " " << bk << " " << hk << "\n";

    double av = ((double) hv)/bv;
    double ak = (v->getmaxy() - v->getminy())/(v->getmaxx() - v->getminx());
    
    cout << "aspectratio's window " << av << " kanaal " << ak << "\n";
    
    // stel in hoe de rechthoek waarbinnen geteken wordt,
    // zichtbaar wordt in het venster
    // dit is afhankelijk van de aspectratio a=h/b
    if (av > ak)
    {
       int b = bv;
       int h = (int) (ak * b);
       p.setViewport(xv, yv + (hv - h)/2, b, h);
    }
    else
    {
       int h = hv;
       int b = (int) (h/ak);
       p.setViewport(xv + (bv - b)/2, yv , b ,h);
    }

    // hiermee stellen we de wereldcoordinaten in    
    p.setWindow(xk, yk, bk, hk);
    
  /*  
    // de vier hoekpunten
    int x1 = xk;
    int y1 = yk;
    int x2 = xk + bk;
    int y2 = yk;
    int x3 = xk + bk;
    int y3 = yk + hk;
    int x4 = xk;
    int y4 = yk + hk;
    
    // diagonaal, alleen voor de test van viewport
    
    p.drawLine(x1, y1, x3, y3);
    p.drawLine(x2, y2, x4, y4);
    
    // rechthoek
    p.drawLine(x1, y1, x2, y2);
    p.drawLine(x2, y2, x3, y3);
    p.drawLine(x3, y3, x4, y4);
    p.drawLine(x4, y4, x1, y1);
    printf("lijn %d %d %d %d\n", xk, yk, xk + bk, yk + hk);
  */  

    // haal de min. en max. diepte voor de kleurbepaling  
    double minz = v->getminz();
    double maxz = v->getmaxz();

    // teken het kanaal    
    v->teken(&p, minz, maxz);
    
    // herstel de instellingen van de qpainter
    p.restore();
}



void Vaart::teken(QPainter *qp, double minz, double maxz)
{
   // teken alle stroken
   for (unsigned int i=0; i<stroken.size(); i++)
   {
      stroken[i]->teken(qp, minz, maxz);
   }
   dieptelijnen->teken(qp);
}

void Strook::teken(QPainter *qp, double minz, double maxz)
{
   // teken alle driehoeken
   for (unsigned int i=0; i<driehoeken.size(); i++)
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
   
   // teken niet gevulde driehoek
   //qp->drawLine(x1, y1, x2, y2);
   //qp->drawLine(x2, y2, x3, y3);
   //qp->drawLine(x3, y3, x1, y1);


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
   polygon.putPoints(0,  3, x1, y1, x2, y2, x3, y3 );
   qp->drawPolygon( polygon );
   
   vector<Punt *> snijpunten;
   if (z12->snijpunt != NULL)
   {
      snijpunten.push_back(z12->snijpunt);
   }
   if (z23->snijpunt != NULL)
   {
      snijpunten.push_back(z23->snijpunt);
   }
   if (z31->snijpunt != NULL)
   {
      snijpunten.push_back(z31->snijpunt);
   }
   
   if (snijpunten.size() == 2)
   {
      
         int x1 = (int) snijpunten[0]->x;
         int y1 = (int) snijpunten[0]->y;
         int x2 = (int) snijpunten[1]->x;
         int y2 = (int) snijpunten[1]->y;
         
         qp->setPen( QColor(0,0,0));
         qp->drawLine(x1, y1, x2, y2);
   }
}


void Dieptelijnen::teken(QPainter *qp)
{
   const int hoogte_streepje = 2;
   
   for (unsigned int iz=0; iz < vzijden.size(); iz++)
   {
      Zijde *zz = vzijden[iz];
      /*
      if (zz->snijding)
      {
         int x1 = (int) zz->p1->x;
         int y1 = (int) zz->p1->y;
         int x2 = (int) zz->p2->x;
         int y2 = (int) zz->p2->y;
         
         qp->setPen( QColor(0,0,0));
         qp->drawLine(x1, y1, x2, y2);
      }
      */
      if (zz->snijpunt != NULL)
      {
         int x1 = (int) zz->snijpunt->x;
         int y1 = (int) zz->snijpunt->y;
         
         qp->setPen( QColor(0,0,0));
         qp->drawLine(x1, y1, x1, y1+hoogte_streepje);
      }
      else
      if (zz->snijvlak != NULL)
      {
         int x1 = (int) zz->p1->x;
         int y1 = (int) zz->p1->y;
         int x2 = (int) zz->p2->x;
         int y2 = (int) zz->p2->y;
         
         qp->setPen( QColor(0,0,0));
         qp->drawLine(x1, y1, x2, y2);
      }
   }
}






// Een item voor Vaart bevat alle items voor de metingen.

QTreeWidgetItem *Vaart::maakitem(QTreeWidget *parent)
{
   QTreeWidgetItem *it = new QTreeWidgetItem(parent);
   it->setText(0, "Vaart");
   
   for (unsigned int i=0; i<metingen.size(); i++)
   {
      QTreeWidgetItem *itk = metingen[i]->maakitem(it);
      it->addChild(itk);
   }
   return it;
}


// Een item voor Meting bevat alle items voor de punten.
QTreeWidgetItem *Meting::maakitem(QTreeWidgetItem *parent)
{
   QTreeWidgetItem *it = new QTreeWidgetItem(parent);
   it->setText(0, "Meting");
   for (unsigned int i=0; i<punten.size(); i++)
   {
      QTreeWidgetItem *itk = punten[i]->maakitem(it);
      it->addChild(itk);
   }
   return it;
}


// Hier wordt een item voor een Punt gemaakt.

QTreeWidgetItem *Punt::maakitem(QTreeWidgetItem *parent)
{
   char bn[50];
   char bx[50];
   char by[50];
   char bz[50];

   // Maak de strings voor de 4 kolommen
   sprintf(bn,"Punt %d", nr);
   sprintf(bx,"%lf", x);
   sprintf(by,"%lf", y);
   sprintf(bz,"%lf", z);

   // Maak het item
   QTreeWidgetItem *it = new QTreeWidgetItem(parent);
   it->setText(0, bn);
   it->setText(1, bx);
   it->setText(2, by);
   it->setText(3, bz);
   
   return it;
}


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    DVenster *w = new DVenster();
    w->setGeometry( 100, 100, 400, 300 );
    //a.setMainWidget( w );
    w->show();
/*
    Dit fragment was nodig om te experimenteren
    met QTreeWidget en QTreeWidgetItem

    QSplitter *spl = new QSplitter(Qt::Vertical);
    QTreeWidget *lv = new QTreeWidget(spl);
    lv->setRootIsDecorated(true);
    lv->addColumn("naam");
    lv->addColumn("x");

    QTreeWidgetItem *it = new QTreeWidgetItem(lv, "een");

    it->insertItem(new QTreeWidgetItem(it, "twee"));
    it->insertItem(new QTreeWidgetItem(it, "drie"));
    it->insertItem(new QTreeWidgetItem(it, "vier"));

    QTreeWidgetItem *it2 = new QTreeWidgetItem(lv, "vijf");

    it2->insertItem(new QTreeWidgetItem(it2, "zes"));
    it2->insertItem(new QTreeWidgetItem(it2, "zeven"));
    it2->insertItem(new QTreeWidgetItem(it2, "acht"));

    it->setExpandable(true);
    it2->setExpandable(true);

    lv->insertItem(it);
    lv->insertItem(it2);

    spl->show();
 */
    return a.exec();
}

