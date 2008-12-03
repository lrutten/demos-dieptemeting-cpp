#include <stdio.h>
#include "vlak.h"
#include "insprong.h"

// $Date: 2008-12-03 16:12:40 $
// $Author: lrutten $
// $Revision: 1.1 $


Vlak::Vlak(double iz) : z(iz)
{
}


void Vlak::toon(int d)
{
   Insprong::springin(d);
   printf("Vlak %lf\n", z);
}


