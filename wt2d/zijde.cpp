#include <iostream>
#include "zijde.h"
#include "insprong.h"

// 7/11/2016
// L. Rutten

int Zijde::teller = 0;

Zijde::Zijde(Punt *ip1, Punt *ip2) : p1(ip1), p2(ip2)
{
   nr = teller++;
   snijding = false;
   snijpunt = NULL;
   snijvlak = NULL;

   zmin = p1->z;
   zmax = p2->z;
   if (p2->z < zmin)
   {
      zmin = p2->z;
      zmax = p1->z;
      
      // verwissel p1 en p2
      // p1 wijst altijd naar het punt met
      // de laagste z
      Punt *h = p1;
      p1 = p2;
      p2 = h;
   }
}

void Zijde::toon(int d)
{
   Insprong::springin(d);
   std::cout << "Zijde " << nr << "\n";
   p1->toon(d + 1);
   p2->toon(d + 1);
}

void Zijde::berekensnijpunt(Vlak *v)
{
   double u;
   
   if (p2->z != p1->z)
   {
      u = (v->z - p1->z)/(p2->z - p1->z);
      if (u >= 0.0 && u <= 1.0)
      {
         snijding = true;
         snijvlak = v;
         std::cout << "u " << u << "\n";
         
         double x = (1.0 - u)*p1->x + u*p2->x;
         double y = (1.0 - u)*p1->y + u*p2->y;
         snijpunt = new Punt(x, y, v->z);
      }
      else
      {
         std::cout << "u buiten bereik\n";
      }
   }
   else
   {
      snijding = true;
      snijvlak = v;
      std::cout << "deling door 0\n";
   }
}

