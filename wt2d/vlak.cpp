#include <iostream>
#include "vlak.h"
#include "insprong.h"

// 7/11/2016
// L. Rutten


Vlak::Vlak(double iz) : z(iz)
{
}


void Vlak::toon(int d)
{
   Insprong::springin(d);
   std::cout << "Vlak " << z << "\n";
}


