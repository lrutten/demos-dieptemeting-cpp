#ifndef METING_H
#define METING_H

#include "punt.h"

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $

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

