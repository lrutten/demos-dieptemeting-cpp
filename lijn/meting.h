#ifndef METING_H
#define METING_H

#include <vector>

#include <QtGui>
#include "punt.h"

// 7/11/2016
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
   QTreeWidgetItem *maakitem(QTreeWidgetItem *parent);

   double berekenminx();
   double berekenmaxx();
   double berekenminy();
   double berekenmaxy();
   double berekenminz();
   double berekenmaxz();
};

#endif

