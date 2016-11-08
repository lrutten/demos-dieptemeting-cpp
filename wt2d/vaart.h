#ifndef VAART_H
#define VAART_H

#include <vector>

#include <Wt/WPainter>

#include "alles.h"

#include "meting.h"
#include "driehoek.h"
#include "strook.h"
#include "zijde.h"
#include "zijden.h"
#include "dieptelijnen.h"

// 8/11/2016
// L. Rutten

class Dieptelijnen;
class Strook;

class Vaart
{
friend class Dieptelijnen;

private:
   std::vector<Meting *> metingen;
   std::vector<Strook *> stroken;
   Dieptelijnen    *dieptelijnen;
   
   double minx;
   double maxx;
   double miny;
   double maxy;
   double minz;
   double maxz;
   
   
public:
   Vaart();
   void voegmetingbij(Meting *m);
   void voegstrookbij(Strook *m);
   void toon(int d = 0);
   void leesbestand(const char *naam);
   int isleeg(char *bf);
   Strook *maakstrook(Meting *m1, Meting *m2);
   void maakstroken();
   void maakdieptelijnen();
   void berekenminmax();
   void teken(Wt::WPainter *qp, double minz, double maxz);
   void dumpobj(const char * bestand);
 
   double getminx()
   {
      return minx;
   }
   double getmaxx()
   {
      return maxx;
   }
   double getminy()
   {
      return miny;
   }
   double getmaxy()
   {
      return maxy;
   }
   double getminz()
   {
      return minz;
   }
   double getmaxz()
   {
      return maxz;
   }
};

#endif
