#ifndef PUNT_H
#define PUNT_H

// $Date: 2008-11-28 15:20:56 $
// $Author: lrutten $
// $Revision: 1.1 $

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
