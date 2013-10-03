#include <stdio.h>
#include "punt.h"
#include "insprong.h"

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $


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
