#include <stdio.h>
#include "vlak.h"
#include "insprong.h"

// $Date$
// $Author$
// $Revision$


Vlak::Vlak(double iz) : z(iz)
{
}


void Vlak::toon(int d)
{
   Insprong::springin(d);
   printf("Vlak %lf\n", z);
}


