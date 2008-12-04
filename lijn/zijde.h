#ifndef ZIJDE_H
#define ZIJDE_H

#include "punt.h"

// $Date: 2008-12-04 09:36:02 $
// $Author: lrutten $
// $Revision: 1.2 $


class Zijde
{
public:
   Punt  *p1;
   Punt  *p2;
   double zmin;
   double zmax;
   bool   snijding;
   int    nr;
   static int teller;
   
   Zijde(Punt *ip1, Punt *ip2);
   void toon(int d = 0);
};

#endif

