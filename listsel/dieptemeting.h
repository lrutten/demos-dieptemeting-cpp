#ifndef DIEPTEMETING_H
#define DIEPTEMETING_H

//#include "moc_dieptemeting.h"
#include "vaart.h"

// $Date: 2006-05-27 20:55:43 $
// $Author: lrutten $
// $Revision: 1.1 $

// dieptemeting met selectie in QListView

class DVenster : public QWidget
{
   Q_OBJECT

public:
   DVenster( QWidget *parent=0, const char *name=0 );
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
   QListView *lv;
   Vaart     *v;
   Driehoek  *dmm;
   Driehoek  *dse;

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


