#ifndef VAART_H
#define VAART_H

//#include <qpainter.h>
//#include <qlistview.h>

#include <QtGui>
#include <Qt3Support/Q3ListView>
#include <Qt3Support/Q3ListViewItem>

#include "meting.h"
#include "strook.h"

// $Date$
// $Author$
// $Revision$


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
   Q3ListViewItem *maakitem(Q3ListView *parent);   
   
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
