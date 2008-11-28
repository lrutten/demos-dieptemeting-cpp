#include <stdio.h>
#include "zijde.h"
#include "insprong.h"

// $Date: 2008-11-28 15:20:56 $
// $Author: lrutten $
// $Revision: 1.1 $

int Zijde::teller = 0;

Zijde::Zijde(Punt *ip1, Punt *ip2) : p1(ip1), p2(ip2)
{
   nr = teller++;
}

void Zijde::toon(int d)
{
   Insprong::springin(d);
   printf("Zijde %d\n", nr);
   p1->toon(d + 1);
   p2->toon(d + 1);
}
