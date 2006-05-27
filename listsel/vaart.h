#ifndef VAART_H
#define VAART_H

#include <qlistview.h>
#include <qpainter.h>
#include "meting.h"
#include "strook.h"

// $Date: 2006-05-27 20:55:44 $
// $Author: lrutten $
// $Revision: 1.1 $


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
   void leesbestand(char *naam);
   int isleeg(char *bf);
   void maakstroken();
   void berekenminmax();
   void teken(QPainter *qp, double minz, double maxz);
   Driehoek *zoek(double x, double y);
   QListViewItem *maakitem(QListView *parent);
   
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
