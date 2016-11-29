#include <iostream>
#include <functional>

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WPaintDevice>
#include <Wt/WPaintedWidget>
#include <Wt/WPainter>

#include <Wt/WBrush>
#include <Wt/WColor>
#include <Wt/WPen>
#include <Wt/WPointF>
#include <Wt/WRectF>

#include "vaart.h"

// 8/11/2016
// L. Rutten

// dieptemeting met Wt toolkit
// En de dieptelijnen worden getoond.

class DWidget : public Wt::WPaintedWidget
{
public:
    DWidget(Wt::WContainerWidget *parent = 0);
    void maakvaart();
    
protected:
    void paintEvent(Wt::WPaintDevice *paintDevice);
    
private:
   Vaart *v;    
};


DWidget::DWidget(Wt::WContainerWidget *parent)
	   : Wt::WPaintedWidget(parent)
{
   resize(2000, 600);   // Provide a default size.

   /*
      Kies voor SVG, canvas of een png afbeelding
    */
   //setPreferredMethod(InlineSvgVml);
   //setPreferredMethod(HtmlCanvas);
   setPreferredMethod(PngImage);

   // bouw alle objecten
   maakvaart();
}


void DWidget::maakvaart()
{
   std::cout << "maakvaart()\n";

   v = new Vaart();
   v->leesbestand("OELG_B06.DAT");
   //v->leesbestand("DATA.DAT");
   v->maakstroken();
   v->berekenminmax();
   v->maakdieptelijnen();

   v->toon();

   //v->dumpobj("java/diepte.obj");
}



void DWidget::paintEvent(Wt::WPaintDevice *paintDevice)
{
   Wt::WPainter p(paintDevice);
   p.setBrush(Wt::WBrush(Wt::WBrush(Wt::blue)));
   p.setPen(Wt::red);

   // Teken een driehoek.
   const Wt::WPointF points[] =  
   {
      Wt::WPointF(10, 10), 
      Wt::WPointF(100, 10),
      Wt::WPointF(100, 100) 
   };
   p.drawPolygon(points, 3);
   
   /*
     Te herwerken
   
   QPainter p( this );
    */
   // sla de instellingen van de qpainter op
   p.save();
    
   // haal de oorsprong, breedte en hoogte op van het venster
   Wt::WRectF r = p.viewPort();
   int xv = r.left();
   int yv = r.top();
   int bv = r.width();
   int hv = r.height();
   std::cout << "viewport " << xv << " " << yv << " " << bv << " " << hv << "\n";

   // haal de oorsprong, breedte en hoogte op van het kanaal
   int xk = (int) v->getminx();
   int yk = (int) v->getminy();
   int bk = (int) (v->getmaxx() - v->getminx());
   int hk = (int) (v->getmaxy() - v->getminy());
   std::cout << "window " << xk << " " << yk << " " << bk << " " << hk << "\n";

   double av = ((double) hv)/bv;
   double ak = (v->getmaxy() - v->getminy())/(v->getmaxx() - v->getminx());
    
   std::cout << "aspectratio's window " << av << " kanaal " << ak << "\n";
    
   // stel in hoe de rechthoek waarbinnen geteken wordt,
   // zichtbaar wordt in het venster
   // dit is afhankelijk van de aspectratio a=h/b
   if (av > ak)
   {
      int b = bv;
      int h = (int) (ak * b);
      p.setViewPort(xv, yv + (hv - h)/2, b, h);
   }
   else
   {
      int h = hv;
      int b = (int) (h/ak);
      p.setViewPort(xv + (bv - b)/2, yv , b ,h);
   }

   // hiermee stellen we de wereldcoordinaten in    
   p.setWindow(xk, yk, bk, hk);
    

   // haal de min. en max. diepte voor de kleurbepaling  
   double minz = v->getminz();
   double maxz = v->getmaxz();

   // teken het kanaal    
   v->teken(&p, minz, maxz);
    
   // herstel de instellingen van de wpainter
   p.restore();
}



void Vaart::teken(Wt::WPainter *qp, double minz, double maxz)
{
   // teken alle stroken
   for (unsigned int i=0; i<stroken.size(); i++)
   {
      stroken[i]->teken(qp, minz, maxz);
   }
   dieptelijnen->teken(qp);
}

void Strook::teken(Wt::WPainter *qp, double minz, double maxz)
{
   // teken alle driehoeken
   for (unsigned int i=0; i<driehoeken.size(); i++)
   {
      driehoeken[i]->teken(qp, minz, maxz);
   }
   
}

// teken een driehoek met een vulkleur volgens diepte

void Driehoek::teken(Wt::WPainter *qp, double minz, double maxz)
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
   qp->setPen(Wt::WPen(Wt::WColor(r,g,b)));
   
   // stel de vulkleur in
   qp->setBrush(Wt::WBrush(Wt::WColor(r,g,b)));
   
   
   // teken gevulde driehoek
   //QPolygon polygon(3);
   //polygon.putPoints(0,  3, x1, y1, x2, y2, x3, y3 );
   //qp->drawPolygon( polygon );

   
   const Wt::WPointF points[] =  
   {
      Wt::WPointF(x1, y1), 
      Wt::WPointF(x2, y2),
      Wt::WPointF(x3, y3) 
   };
   qp->drawPolygon(points, 3);
   
   std::vector<Punt *> snijpunten;
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
         
         qp->setPen( Wt::WColor(0,0,0));
         qp->drawLine(x1, y1, x2, y2);
   }
}


void Dieptelijnen::teken(Wt::WPainter *qp)
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
         
         qp->setPen(Wt::WColor(0,0,0));
         qp->drawLine(x1, y1, x1, y1+hoogte_streepje);
      }
      else
      if (zz->snijvlak != NULL)
      {
         int x1 = (int) zz->p1->x;
         int y1 = (int) zz->p1->y;
         int x2 = (int) zz->p2->x;
         int y2 = (int) zz->p2->y;
         
         qp->setPen(Wt::WColor(0,0,0));
         qp->drawLine(x1, y1, x2, y2);
      }
   }
}


class DiepteApplication : public Wt::WApplication
{
public:
   DiepteApplication(const Wt::WEnvironment& env);

private:
};

DiepteApplication::DiepteApplication(const Wt::WEnvironment& env)
  : Wt::WApplication(env)
{
   setTitle("Dieptemeting");

   Wt::WContainerWidget *container = new Wt::WContainerWidget();
   DWidget *painting = new DWidget(container);
   
   root()->addWidget(container);
}

Wt::WApplication *createApplication(const Wt::WEnvironment& env)
{
   return new DiepteApplication(env);
}

int main(int argc, char **argv)
{
   return Wt::WRun(argc, argv, &createApplication);
}

