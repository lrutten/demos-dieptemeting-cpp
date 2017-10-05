#ifndef METING_H
#define METING_H

#include <QtGui>
#include <Qt3Support/Q3ListView>
#include <Qt3Support/Q3ListViewItem>

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
   Q3ListViewItem *maakitem(Q3ListViewItem *parent);

   double berekenminx();
   double berekenmaxx();
   double berekenminy();
   double berekenmaxy();
   double berekenminz();
   double berekenmaxz();
};

#endif

