#ifndef PUNT_H
#define PUNT_H

// 8/11/2016
// L. Rutten

#include <Wt/WPainter>

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
