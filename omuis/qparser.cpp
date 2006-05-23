/****************************************************************
**
** Qt figuren vb
**
****************************************************************/

#include <qapplication.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qpainter.h>
#include <qscrollview.h>
#include <vector>

using namespace std;

#include "parser.h"

class PVenster : public QWidget
{
public:
    PVenster( QWidget *parent=0, const char *name=0 );

protected:
    void paintEvent( QPaintEvent * );
    void mouseMoveEvent( QMouseEvent * );
    void mousePressEvent( QMouseEvent * );

private:
   Uitdrukking *u;
   Uitdrukking *umm;
   Uitdrukking *use;
};


PVenster::PVenster( QWidget *parent, const char *name )
        : QWidget( parent, name )
{
   //setMinimumSize( 400, 300 );
   //setMaximumSize( 400, 300 );

   // hierdoor krijg je ook mouse move events
   // zonder de muisknop ingedrukt
   setMouseTracking(true);
   
   // nog geen uitdrukking onder muis
   umm = NULL;
   
   // nog geen selectie
   use = NULL;
   
   // maak een Parser
   Parser *p = new Parser();
   u = p->parse("1/((1234+2)/(3456+3))*(48+5456)");
}

void PVenster::paintEvent(QPaintEvent *)
{
   QPainter p( this );
    
   p.setBackgroundMode(Qt::OpaqueMode);
   p.setBackgroundColor(Qt::white);
   p.eraseRect(0,0, u->getb(), u->geth());
   
   u->teken(&p, 0, 0);

   setGeometry(0,0,u->getb(), u->geth());
}

void PVenster::mouseMoveEvent(QMouseEvent *ev)
{
   int x = ev->x();
   int y = ev->y();
   printf("mm %d %d\n", x, y);
   
   // zoek uitdrukking onder muis
   Uitdrukking *ur = u->zoek(x,y);
   
   if (ur != umm)
   {
      if (umm != NULL)
      {
         umm->setomuis(false);
      }
      if (ur != NULL)
      {
         ur->setomuis(true);
      }
      umm = ur;
      repaint();
   }
}

void PVenster::mousePressEvent(QMouseEvent *ev)
{
   if (umm != use)
   {
      if (use != NULL)
      {
         use->setomuis(false);
         use->setselectie(false);
      }
      if (umm != NULL)
      {
         umm->setselectie(true);
      }
      use = umm;
      repaint();
   }
}


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    QScrollView *s = new QScrollView();
    PVenster *p = new PVenster();
    s->addChild(p);
    
    a.setMainWidget( s );
    s->show();
    return a.exec();
}

