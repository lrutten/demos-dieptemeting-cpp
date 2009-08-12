#ifndef METING_H
#define METING_H

#include <qlistview.h>
#include "punt.h"

// $Date$
// $Author$
// $Revision$

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

