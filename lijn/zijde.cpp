#include <stdio.h>
#include "zijde.h"
#include "insprong.h"

// $Date: 2008-12-04 09:36:02 $
// $Author: lrutten $
// $Revision: 1.2 $

int Zijde::teller = 0;

Zijde::Zijde(Punt *ip1, Punt *ip2) : p1(ip1), p2(ip2)
{
   nr = teller++;
   snijding = false;
   
   zmin = p1->z;
   zmax = p2->z;
   if (p2->z < zmin)
   {
      zmin = p2->z;
      zmax = p1->z;
      
      // verwissel p1 en p2
      // p1 wijst altijd naar het punt met
      // de laagste z
      Punt *h = p1;
      p1 = p2;
      p2 = h;
   }
}

void Zijde::toon(int d)
{
   Insprong::springin(d);
   printf("Zijde %d\n", nr);
   p1->toon(d + 1);
   p2->toon(d + 1);
}
