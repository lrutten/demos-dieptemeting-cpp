#ifndef ZIJDE_H
#define ZIJDE_H

#include "punt.h"

// $Date: 2008-11-28 15:20:56 $
// $Author: lrutten $
// $Revision: 1.1 $


class Zijde
{
public:
   Punt *p1;
   Punt *p2;

   int nr;
   static int teller;
   
   Zijde(Punt *ip1, Punt *ip2);
   void toon(int d = 0);
};

#endif

