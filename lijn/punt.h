#ifndef PUNT_H
#define PUNT_H

// $Date$
// $Author$
// $Revision$

#include <qlistview.h>

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
   QListViewItem *maakitem(QListViewItem *parent);
};

#endif
