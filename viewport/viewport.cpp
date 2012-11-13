#include <stdio.h>
#include <math.h>
#include <QtGui>

class Venster : public QWidget
{
public:
    Venster( QWidget *parent=0);
    
protected:
    void paintEvent( QPaintEvent * );
    
private:
   // viewport
   //  De afmetingen van het venster
   //  in venstercoordinaten (pixel).
   int xv;
   int yv;
   int bv;
   int hv;

   // De afmeting van de figuur
   // in venstercoordinaten.
   int b;
   int h;

   // window
   //  De afmetingen in wereldcoordinaten
   double xf;
   double yf;
   double bf;
   double hf;
};

Venster::Venster( QWidget *parent)
        : QWidget( parent)
{
}

void Venster::paintEvent(QPaintEvent *)
{
    QPainter p( this );
   
    // Sla de instellingen van de qpainter op.
    p.save();
    
    // Haal de oorsprong, breedte en hoogte op van het venster.
    QRect r = p.viewport();

    // hou viewport bij
    xv = r.left();
    yv = r.top();
    bv = r.width();
    hv = r.height();
    printf("viewport %d %d %d %d\n", xv, yv, bv, hv);

    const double pi = 3.14159;

    const double schaal = 1000.0;

    // Bepaal de oorsprong, breedte en hoogte van de figuur.
    xf = -2.0 *pi * schaal;
    yf = -1       * schaal;
    bf = 4.0 * pi * schaal;
    hf = 2.0      * schaal;
    printf("window %lf %lf %lf %lf\n", xf, yf, bf, hf);
    
    // Stel in hoe de rechthoek waarbinnen getekend wordt,
    // zichtbaar wordt in het venster.
    // Boven, onder, links en rechts is er een rand van 20 pixels.
    const int rand = 20;
    p.setViewport(xv+rand, yv+rand, bv-2*rand, hv-2*rand);

    // Hiermee stellen we de wereldcoordinaten in.
    p.setWindow((int)xf, (int)yf, (int)bf, (int)hf);

    // Teken een diagonale lijn.
    p.drawLine((int)xf, (int)yf, (int)(xf+bf), (int)(yf+hf));
    printf("drawLine %d %d %d %d\n", (int)xf, (int)yf, (int)(xf+bf), (int)(yf+hf));

    // Teken een sinus van 2 perioden 
    // op een schaal van 1000.
    double step = pi/24.0; 
    double t = -2.0*pi + step;
    while (t <= 2.0*pi)
    {
       double p1x = schaal *(t - step);
       double p1y = schaal * sin(t - step);
       double p2x = schaal * t;
       double p2y = schaal * sin(t);

       p.drawLine((int)p1x, (int)p1y, (int)p2x, (int)p2y);
       
       t += step;
    }
    // herstel de instellingen van de qpainter
    p.restore();
}

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    Venster w;
    w.setGeometry( 100, 100, 400, 300 );
    w.show();

    return a.exec();
}
