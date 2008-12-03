#ifndef VAART_H
#define VAART_H

#include <vector>

#include <qpainter.h>
#include <qlistview.h>
#include "meting.h"
#include "strook.h"
#include "zijden.h"
#include "dieptelijnen.h"

using namespace std;

// $Date: 2008-12-03 13:04:23 $
// $Author: lrutten $
// $Revision: 1.3 $

class Dieptelijnen;

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
   void leesbestand(char *naam);
   int isleeg(char *bf);
   void maakstroken();
   void maakdieptelijnen();
   void berekenminmax();
   void teken(QPainter *qp, double minz, double maxz);
   QListViewItem *maakitem(QListView *parent);
   void dumpobj(char * bestand);
 
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
