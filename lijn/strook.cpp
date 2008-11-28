#include <stdio.h>
#include "strook.h"
#include "insprong.h"

// $Date: 2008-11-28 15:20:56 $
// $Author: lrutten $
// $Revision: 1.1 $


Strook::Strook()
{
   ndriehoeken = 0;
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

