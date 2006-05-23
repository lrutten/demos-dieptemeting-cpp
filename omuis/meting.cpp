#include <stdio.h>
#include "meting.h"
#include "insprong.h"

// $Date: 2006-05-23 07:59:07 $
// $Author: lrutten $
// $Revision: 1.1 $


Meting::Meting()
{
   npunten = 0;
}

void Meting::voegpuntbij(Punt *p)
{
   punten[npunten++] = p;  
}

void Meting::toon(int d)
{
   Insprong::springin(d);
   printf("Meting\n");
   for (int i = 0; i<npunten; i++)
   {
      punten[i]->toon(d + 1);
   }
}

double Meting::berekenminx()
{
   double min;
   
   min = punten[0]->x;
   
   for (int i=1; i<npunten; i++)
   {
      if (punten[i]->x < min)
      {
         min = punten[i]->x;
      }
   }
   return min;
}

double Meting::berekenmaxx()
{
   double max;
   
   max = punten[0]->x;
   
   for (int i=1; i<npunten; i++)
   {
      if (punten[i]->x > max)
      {
         max = punten[i]->x;
      }
   }
   return max;
}

double Meting::berekenminy()
{
   double min;
   
   min = punten[0]->y;
   
   for (int i=1; i<npunten; i++)
   {
      if (punten[i]->y < min)
      {
         min = punten[i]->y;
      }
   }
   return min;
}

double Meting::berekenmaxy()
{
   double max;
   
   max = punten[0]->y;
   
   for (int i=1; i<npunten; i++)
   {
      if (punten[i]->y > max)
      {
         max = punten[i]->y;
      }
   }
   return max;
}

double Meting::berekenminz()
{
   double min;
   
   min = punten[0]->z;
   
   for (int i=1; i<npunten; i++)
   {
      if (punten[i]->z < min)
      {
         min = punten[i]->z;
      }
   }
   return min;
}

double Meting::berekenmaxz()
{
   double max;
   
   max = punten[0]->z;
   
   for (int i=1; i<npunten; i++)
   {
      if (punten[i]->z > max)
      {
         max = punten[i]->z;
      }
   }
   return max;
}



