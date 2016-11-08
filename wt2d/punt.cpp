#include <iostream>
#include "punt.h"
#include "insprong.h"

// 7/11/2016
// L. Rutten

int Punt::teller = 0;

Punt::Punt(double ix, double iy, double iz) : x(ix), y(iy), z(iz)
{
   nr = ++teller;
}

void Punt::toon(int d)
{
   Insprong::springin(d);
   std::cout << "Punt nr: " << nr << " " << x << " " << y << " " << z << "\n";
}
