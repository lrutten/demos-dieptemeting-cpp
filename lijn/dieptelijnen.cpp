#include <stdio.h>
#include "dieptelijnen.h"
#include "insprong.h"

// $Date: 2008-12-03 16:12:40 $
// $Author: lrutten $
// $Revision: 1.2 $


Dieptelijnen::Dieptelijnen(Vaart *v, double dz) : vaart(v), deltaz(dz)
{
   zijden = new Zijden();
}


void Dieptelijnen::toon(int d)
{
   Insprong::springin(d);
   printf("Dieptelijnen\n");
   //zijden->toon(d + 1);
   
   Insprong::springin(d + 1);
   printf("Vlakken\n");
   for (int iv=0; iv < vlakken.size(); iv++)
   {
      vlakken[iv]->toon(d + 2);
   }
}

void Dieptelijnen::maakdieptelijnen()
{
   maakzijden();
   maakvlakken();
}

void Dieptelijnen::maakzijden()
{
   printf("Dieptelijnen::maakzijden()\n");
 
   for (int is=0; is < vaart->stroken.size(); is++)
   {
      Strook *s = vaart->stroken[is];
      
      for (int id=0; id <s->driehoeken.size(); id++)
      {
         Driehoek *d = s->driehoeken[id];
         zijden->voegdriehoekbij(d);
      }
   }
}

void Dieptelijnen::maakvlakken()
{
   printf("Dieptelijnen::maakvlakken()\n");
   printf("deltaz %lf\n", deltaz);
   printf("zmin   %lf\n", vaart->minz);
   printf("zmax   %lf\n", vaart->maxz);
   
   int dz  = (int) deltaz;
   int miz = (int) vaart->minz;
   int maz = (int) vaart->maxz;
   //int miz = 100;
   //int maz = 600;
   
   int   t = dz;
   int zmi = miz/dz;
   printf("%d * %d\n", zmi, t);

       zmi *= t;
         t = dz;
   int zma = maz/dz; 
   if ((maz % dz) != 0)
   {
      zma++;
   }
   zma *= t;

   printf("dz    %d\n", dz);
   printf("zmi   %d\n", zmi);
   printf("zma   %d\n", zma);
   
   int z = zmi;
   while (z <= zma)
   {
      printf("z %d\n", z);
      Vlak *v = new Vlak(z);
      vlakken.push_back(v);
      z += dz;
   }
   
   for (int iv=0; iv < vlakken.size(); iv++)
   {
      Vlak *v = vlakken[iv];
      printf("vlak z %lf\n", v->z);
      
      map<Punt *, map<Punt *, Zijde *> >::iterator ir= zijden->zijden.begin();
      while (ir != zijden->zijden.end())
      {
         //Punt *p = (*ir).first;
         map<Punt *, Zijde *>::iterator ik = (*ir).second.begin();
         while (ik != (*ir).second.end())
         {
            //Punt *q = (*ik).first;
            Zijde *zz = (*ik).second;
            //zz->toon(0);
   
            ik++;
         }
         ir++;
      }
   }
}

