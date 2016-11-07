#include <iostream>
#include "strook.h"
#include "insprong.h"

// 7/11/2016
// L. Rutten


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
   std::cout << "Strook\n";
   for (unsigned int i = 0; i<driehoeken.size(); i++)
   {
      driehoeken[i]->toon(d + 1);
   }
}

void Strook::dumpobj(FILE *fp)
{

}

