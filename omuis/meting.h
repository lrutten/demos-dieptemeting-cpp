#ifndef METING_H
#define METING_H

#include "punt.h"

// $Date: 2006-05-23 07:59:07 $
// $Author: lrutten $
// $Revision: 1.1 $

class Meting
{
friend class Vaart;
friend class Strook;
   
private:
   int npunten;
   Punt *punten[50];
   
public:
   Meting();
   void voegpuntbij(Punt *p);
   void toon(int d = 0);
   
   double berekenminx();
   double berekenmaxx();
   double berekenminy();
   double berekenmaxy();
   double berekenminz();
   double berekenmaxz();
};

#endif

