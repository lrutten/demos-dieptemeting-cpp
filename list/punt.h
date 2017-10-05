#ifndef PUNT_H
#define PUNT_H

// $Date$
// $Author$
// $Revision$

#include <QtGui>
#include <Qt3Support/Q3ListView>
#include <Qt3Support/Q3ListViewItem>

class Punt
{
friend class Vaart;

public:
   double x;
   double y;
   double z;

   int nr;
   static int teller;
   
   Punt(double ix, double iy, double iz);
   void toon(int d = 0);
   Q3ListViewItem *maakitem(Q3ListViewItem *parent);
};

#endif
