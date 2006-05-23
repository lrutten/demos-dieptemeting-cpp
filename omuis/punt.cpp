#include <stdio.h>
#include "punt.h"
#include "insprong.h"

// $Date: 2006-05-23 07:59:07 $
// $Author: lrutten $
// $Revision: 1.1 $


int Punt::teller = 0;

Punt::Punt(double ix, double iy, double iz) : x(ix), y(iy), z(iz)
{
   nr = teller++;
}

void Punt::toon(int d)
{
   Insprong::springin(d);
   printf("Punt %d: %lf %lf %lf\n", nr, x, y, z);
}
