#include <iostream>
#include "driehoek.h"
#include "insprong.h"

// 7/11/2016
// L. Rutten

Driehoek::Driehoek(Punt *ip1, Punt *ip2, Punt *ip3) : p1(ip1), p2(ip2), p3(ip3)
{
}

void Driehoek::toon(int d)
{
   Insprong::springin(d);
   std::cout << "Driehoek\n";
   p1->toon(d + 1);
   p2->toon(d + 1);
   p3->toon(d + 1);
}

void Driehoek::dumpobj(FILE *fp)
{

}

