#ifndef METING_H
#define METING_H

#include <qlistview.h>
#include "punt.h"

// $Date: 2006-05-23 14:20:18 $
// $Author: lrutten $
// $Revision: 1.1 $

class Meting
{
friend class Vaart;
   
private:
   int npunten;
   Punt *punten[50];
   
public:
   Meting();
   void voegpuntbij(Punt *p);
   void toon(int d = 0);
   QListViewItem *maakitem(QListViewItem *parent);

   double berekenminx();
   double berekenmaxx();
   double berekenminy();
   double berekenmaxy();
   double berekenminz();
   double berekenmaxz();
};

#endif

