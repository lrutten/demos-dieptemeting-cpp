#ifndef PUNT_H
#define PUNT_H

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $


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
