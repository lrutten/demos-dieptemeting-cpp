#include <stdio.h>
#include "driehoek.h"
#include "insprong.h"

// $Date: 2003-12-16 12:18:48 $
// $Author: lrutten $
// $Revision: 1.1 $

Driehoek::Driehoek(Punt *ip1, Punt *ip2, Punt *ip3) : p1(ip1), p2(ip2), p3(ip3)
{
}

void Driehoek::toon(int d)
{
   Insprong::springin(d);
   printf("Driehoek\n");
   p1->toon(d + 1);
   p2->toon(d + 1);
   p3->toon(d + 1);
}
