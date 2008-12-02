#include <stdio.h>
#include "strook.h"
#include "insprong.h"

// $Date: 2008-12-02 09:59:55 $
// $Author: lrutten $
// $Revision: 1.2 $


Strook::Strook()
{
}

void Strook::voegdriehoekbij(Driehoek *d)
{
   driehoeken.push_back(d);  
}

void Strook::toon(int d)
{
   Insprong::springin(d);
   printf("Strook\n");
   for (int i = 0; i<driehoeken.size(); i++)
   {
      driehoeken[i]->toon(d + 1);
   }
}

void Strook::dumpobj(FILE *fp)
{

}

