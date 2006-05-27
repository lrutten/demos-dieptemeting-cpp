#ifndef PUNT_H
#define PUNT_H

// $Date: 2006-05-27 20:55:43 $
// $Author: lrutten $
// $Revision: 1.1 $


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
};

#endif
