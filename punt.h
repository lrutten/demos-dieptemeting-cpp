#ifndef PUNT_H
#define PUNT_H

// $Date: 2003-12-16 12:18:48 $
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
