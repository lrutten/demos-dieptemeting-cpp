#ifndef METING_H
#define METING_H

#include <vector>

#include <Wt/WPainter>
#include "punt.h"

// 8/11/2016
// L. Rutten

class Meting
{
friend class Vaart;
   
private:
   std::vector<Punt *> punten;
   
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

