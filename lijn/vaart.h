#ifndef VAART_H
#define VAART_H

#include <vector>

#include <QtGui>

#include "alles.h"

#include "meting.h"
#include "driehoek.h"
#include "strook.h"
#include "zijde.h"
#include "zijden.h"
#include "dieptelijnen.h"

using namespace std;

// $Date$
// $Author$
// $Revision$

class Dieptelijnen;
class Strook;

class Vaart
{
friend class Dieptelijnen;

private:
   vector<Meting *> metingen;
   vector<Strook *> stroken;
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
   void maakstroken();
   void maakdieptelijnen();
   void berekenminmax();
   void teken(QPainter *qp, double minz, double maxz);
   QTreeWidgetItem *maakitem(QTreeWidget *parent);
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
