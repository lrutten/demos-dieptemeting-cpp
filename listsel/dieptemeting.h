#ifndef DIEPTEMETING_H
#define DIEPTEMETING_H

//#include "moc_dieptemeting.h"
#include "vaart.h"

// $Date$
// $Author$
// $Revision$

// dieptemeting met selectie in QListView

class DVenster : public QWidget
{
   Q_OBJECT

public:
   DVenster( QWidget *parent=0);
   void maakvaart();
   void maakboom();
    
protected:
   void paintEvent( QPaintEvent * );
   void mouseMoveEvent( QMouseEvent * );
   void mousePressEvent( QMouseEvent * );


public slots:    
//   void slotLVChanged(QListViewItem *item);
   void slotLVChanged();
    
private:
   Q3ListView *lv;
   Vaart      *v;
   Driehoek   *dmm;
   Driehoek   *dse;

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

#endif


