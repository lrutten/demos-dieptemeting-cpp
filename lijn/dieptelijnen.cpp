#include <stdio.h>
#include "dieptelijnen.h"
#include "insprong.h"

// $Date: 2008-12-03 13:04:22 $
// $Author: lrutten $
// $Revision: 1.1 $


Dieptelijnen::Dieptelijnen(Vaart *v, int dz) : vaart(v), deltaz(dz)
{
   zijden = new Zijden();
}


void Dieptelijnen::toon(int d)
{
   Insprong::springin(d);
   printf("Dieptelijnen\n");
}

void Dieptelijnen::maakdieptelijnen()
{
   maakzijden();
}

void Dieptelijnen::maakzijden()
{
   printf("Dieptelijnen::maakzijden()\n");
 
   for (int is=0; is < vaart->stroken.size(); is++)
   {
   }
}
