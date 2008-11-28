#include <stdio.h>
#include "zijden.h"
#include "insprong.h"

// $Date: 2008-11-28 15:20:56 $
// $Author: lrutten $
// $Revision: 1.1 $


Zijden::Zijden()
{
}

/*
void Zijden::voegzijdebij(Zijde *z)
{
   zijden.push_back(z);  
}
*/

void Zijden::voegdriehoekbij(Driehoek *d)
{
   printf("Zijden::voegdriehoekbij()\n");
   Zijde *z12 = voegzijdebij(d->p1, d->p2);
   printf("z12 %p\n", z12);

   Zijde *z23 = voegzijdebij(d->p2, d->p3);
   printf("z23 %p\n", z23);

   Zijde *z31 = voegzijdebij(d->p3, d->p1);
   printf("z31 %p\n", z31);

   d->z12 = z12;
   d->z23 = z23;
   d->z31 = z31;
   
}

Zijde *Zijden::voegzijdebij(Punt *p1, Punt *p2)
{
   printf("Zijden::voegzijdehoekbij()\n");
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
   zijden[p1][p2] = z;
   return z;
}


/*
  Zoek een zijde in de dubbele map
 */

Zijde *Zijden::zoek(Punt *p1, Punt *p2)
{
   map<Punt *, map<Punt *, Zijde *> >::iterator it1 = zijden.find(p1);
   if (it1 != zijden.end())
   {
      printf("p1a gevonden\n");
      map<Punt *, Zijde *> map2 = (*it1).second;
      map<Punt *, Zijde *>::iterator it2 = map2.find(p2);
      if (it2 != map2.end())
      {
         printf("p2a gevonden\n");
         return (*it2).second;
      }
      else
      {
         return NULL;
      }
   }
   else
   {
      it1 = zijden.find(p2);
      if (it1 != zijden.end())
      {
         printf("p2b gevonden\n");
         map<Punt *, Zijde *> map2 = (*it1).second;
         map<Punt *, Zijde *>::iterator it2 = map2.find(p1);
         if (it2 != map2.end())
         {
            printf("p1b gevonden\n");
            return (*it2).second;
         }
         else
         {
            return NULL;
         }
      }
      else
      {
         return NULL;
      }
   }
}

void Zijden::toon(int d)
{
   Insprong::springin(d);
   printf("Zijden\n");

   map<Punt *, map<Punt *, Zijde *> >::iterator ir= zijden.begin();
   while (ir != zijden.end())
   {
      Punt *p = (*ir).first;
      p->toon(d+1);
      map<Punt *, Zijde *>::iterator ik = (*ir).second.begin();
      while (ik != (*ir).second.end())
      {
         Punt *q = (*ik).first;
         q->toon(d+2);
         Zijde *z = (*ik).second;
         z->toon(d+3);

         ik++;
      }
      ir++;
   }
}

