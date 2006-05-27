#include <stdio.h>
#include "strook.h"
#include "insprong.h"

// $Date: 2006-05-27 20:55:43 $
// $Author: lrutten $
// $Revision: 1.1 $


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
   printf("Strook\n");
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
