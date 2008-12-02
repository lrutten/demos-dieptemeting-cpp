#ifndef VAART_H
#define VAART_H

#include <vector>

#include <qpainter.h>
#include <qlistview.h>
#include "meting.h"
#include "strook.h"
#include "zijden.h"

using namespace std;

// $Date: 2008-12-02 09:59:55 $
// $Author: lrutten $
// $Revision: 1.2 $


class Vaart
{
private:
   vector<Meting *> metingen;
   vector<Strook *> stroken;
   Zijden *zijden;
   
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
