#ifndef ZIJDE_H
#define ZIJDE_H

#include "alles.h"
#include "punt.h"
#include "vlak.h"

// $Date$
// $Author$
// $Revision$


class Zijde
{
public:
   Punt  *p1;
   Punt  *p2;
   Punt  *snijpunt;
   Vlak  *snijvlak;
   double zmin;
   double zmax;
   bool   snijding;
   int    nr;
   static int teller;
   
   Zijde(Punt *ip1, Punt *ip2);
   void toon(int d = 0);
   void berekensnijpunt(Vlak *v);
};

#endif

