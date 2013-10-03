#include <iostream>
#include "strook.h"
#include "insprong.h"

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $


Strook::Strook(Meting *mm1, Meting *mm2)
{
   ndriehoeken = 0;
   m1 = mm1;
   m2 = mm2;
}

void Strook::voegdriehoekbij(Driehoek *d)
{
   driehoeken[ndriehoeken++] = d;  
}

void Strook::toon(int d)
{
   Insprong::springin(d);
   cout << "Strook\n";
   for (int i = 0; i<ndriehoeken; i++)
   {
      driehoeken[i]->toon(d + 1);
   }
}

Driehoek *Strook::zoek(double x, double y)
{
   if (x  < m1->punten[0]->x ||
       x >= m2->punten[0]->x)
   {
      return NULL;
   }
   else
   {
      int i=0;
      while (i<ndriehoeken && driehoeken[i]->p1->y < y)
      {
         i++;
      }
      if (i < ndriehoeken)
      {
         return driehoeken[i];
      }
      else
      {
         return NULL;
      }
   }
}
