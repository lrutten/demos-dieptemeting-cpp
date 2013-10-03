#ifndef VAART_H
#define VAART_H

#include "qpainter.h"
#include "meting.h"
#include "strook.h"

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $

#include <string>
using namespace std;

class Vaart
{
private:
   int nmetingen;
   Meting *metingen[2500];
   int nstroken;
   Strook *stroken[2500];
   
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
   bool isleeg(const string &bf);
   void maakstroken();
   void berekenminmax();
   void teken(QPainter *qp, double minz, double maxz);
   Driehoek *zoek(double x, double y);
   int  naarint(const string &s);
   double naardouble(const string &s);
   
   
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
