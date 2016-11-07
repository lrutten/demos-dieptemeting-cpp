#include <stdio.h>
#include "zijden.h"
#include "insprong.h"

// 7/11/2016
// $Author$
// $Revision$


Zijden::Zijden()
{
}

void Zijden::voegdriehoekbij(Driehoek *d)
{
   //printf("Zijden::voegdriehoekbij()\n");
   Zijde *z12 = voegzijdebij(d->p1, d->p2);
   //printf("z12 %p\n", z12);

   Zijde *z23 = voegzijdebij(d->p2, d->p3);
   //printf("z23 %p\n", z23);

   Zijde *z31 = voegzijdebij(d->p3, d->p1);
   //printf("z31 %p\n", z31);

   d->z12 = z12;
   d->z23 = z23;
   d->z31 = z31;
   
}

Zijde *Zijden::voegzijdebij(Punt *p1, Punt *p2)
{
   //printf("Zijden::voegzijdehoekbij()\n");
   Zijde *z = zoek(p1, p2);
   if (z != NULL)
   {
      return z;
   }
   
   z = zoek(p2, p1);
   if (z != NULL)
   {
      return z;
   }
   z = new Zijde(p1, p2);
   zijden[std::pair<Punt *, Punt *>(p1, p2)] = z;
   return z;
}


/*
  Zoek een zijde in de map
 */

Zijde *Zijden::zoek(Punt *p1, Punt *p2)
{
   std::pair<Punt *, Punt *> paar(p1, p2);
   
   std::map<std::pair<Punt *, Punt *>, Zijde *>::iterator it = zijden.find(paar);
   if (it != zijden.end())
   {
      //printf("p1a gevonden\n");
      return (*it).second;
   }
   else
   {
      return NULL;
   }
}

void Zijden::toon(int d)
{
   Insprong::springin(d);
   printf("Zijden\n");

   std::map<std::pair<Punt *, Punt *>, Zijde *>::iterator it= zijden.begin();
   while (it != zijden.end())
   {
      Punt *p1 = (*it).first.first;
      p1->toon(d+1);
      Punt *p2 = (*it).first.second;
      p2->toon(d+1);
      Zijde *z = (*it).second;
      z->toon(d+2);
      it++;
   }
}

