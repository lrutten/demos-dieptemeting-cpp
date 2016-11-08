#include <iostream>
#include "dieptelijnen.h"
#include "insprong.h"

#include <algorithm>

// 8/11/2016
// L. Rutten

Dieptelijnen::Dieptelijnen(Vaart *v, double dz) : vaart(v), deltaz(dz)
{
   zijden = new Zijden();
}


void Dieptelijnen::toon(int d)
{
   Insprong::springin(d);
   std::cout << "Dieptelijnen\n";
   //zijden->toon(d + 1);
   
   Insprong::springin(d + 1);
   std::cout << "Vlakken\n";
   for (unsigned int iv=0; iv < vlakken.size(); iv++)
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
   std::cout << "Dieptelijnen::maakzijden()\n";
 
   for (unsigned int is=0; is < vaart->stroken.size(); is++)
   {
      Strook *s = vaart->stroken[is];
      
      for (unsigned int id=0; id <s->driehoeken.size(); id++)
      {
         Driehoek *d = s->driehoeken[id];
         zijden->voegdriehoekbij(d);
      }
   }
}

// vergelijk twee zijden op de max z
bool cmp(const Zijde *a, const Zijde *b)
{
   return a->zmax < b->zmax;
}

void Dieptelijnen::maakvlakken()
{
   std::cout << "Dieptelijnen::maakvlakken()\n";
   std::cout << "deltaz " << deltaz << "\n";
   std::cout << "zmin   " << vaart->minz << "\n";
   std::cout << "zmax   " << vaart->maxz << "\n";
 
   int dz  = (int) deltaz;
   int miz = (int) vaart->minz;
   int maz = (int) vaart->maxz;
   //int miz = 100;
   //int maz = 600;
   
   int   t = dz;
   int zmi = miz/dz;
   std::cout << zmi << " * " << t << "\n";

       zmi *= t;
         t = dz;
   int zma = maz/dz; 
   if ((maz % dz) != 0)
   {
      zma++;
   }
   zma *= t;

   std::cout << "dz    " << dz  << "\n"; 
   std::cout << "zmi   " << zmi << "\n";
   std::cout << "zma   " << zma << "\n";
   
   int z = zmi;
   while (z <= zma)
   {
      std::cout << "z " << z << "\n";
      Vlak *v = new Vlak(z);
      vlakken.push_back(v);
      z += dz;
   }

   // overloop alle zijden
   std::map<std::pair<Punt *, Punt *>, Zijde *>::iterator it= zijden->zijden.begin();
   while (it != zijden->zijden.end())
   {
      //Punt *p = (*it).first.first;
      //Punt *q = (*it).first.second;
      Zijde *zz = (*it).second;
      //zz->toon(0);
         
      // kopieer de zijde naar de vector
      vzijden.push_back(zz);
      it++;
   }

   // sorteer de lijst
   std::sort(vzijden.begin(), vzijden.end(), cmp);
   
   /*
   for (unsigned int i=0; i<vzijden.size(); i++)
   {
      Zijde *zij = vzijden[i];
      printf("zijde zmin %lf zmax %lf df %lf\n", zij->zmin, zij->zmax, zij->zmax - zij->zmin);
   }
    */
   
   // overloop alle vlakken
   // en tegelijkertijd de zijden
   //int iz = 0;
   for (unsigned int iv=0; iv < vlakken.size(); iv++)
   {
      Vlak *v = vlakken[iv];
      std::cout << "vlak z " << v->z << "\n";
      
      // sla de zijden met een te lage z over
      /*
      while (iz < vzijden.size() && vzijden[iz]->zmax < v->z)
      {
         Zijde *zij = vzijden[iz];
         printf("v zmax laag %lf zijde zmin %lf zmax %lf df %lf\n", v->z, zij->zmin, zij->zmax, zij->zmax - zij->zmin);
         
         iz++;
      }
      */
      
      for (unsigned int iz = 0; iz < vzijden.size(); iz++)
      {
         if (vzijden[iz]->zmin <= v->z && vzijden[iz]->zmax >= v->z)
         {
            Zijde *zij = vzijden[iz];
            zij->snijding = true;
            std::cout << "v "   << v->z << "zmax ok  zijde zmin " << zij->zmin << " zmax " << zij->zmax 
                 << " df " << (zij->zmax - zij->zmin) << "\n";
            zij->berekensnijpunt(v);
         }
      }
   }
}

