#ifndef METING_H
#define METING_H

#include "punt.h"

// $Date$
// $Author$
// $Revision$

class Meting
{
friend class Vaart;
   
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

