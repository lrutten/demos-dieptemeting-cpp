#include <iostream>
#include "driehoek.h"
#include "insprong.h"

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $

Driehoek::Driehoek(Punt *ip1, Punt *ip2, Punt *ip3) : p1(ip1), p2(ip2), p3(ip3)
{
}

void Driehoek::toon(int d)
{
   Insprong::springin(d);
   cout << "Driehoek\n";
   p1->toon(d + 1);
   p2->toon(d + 1);
   p3->toon(d + 1);
}
