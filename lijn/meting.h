#ifndef METING_H
#define METING_H

#include <vector>

#include <qlistview.h>
#include "punt.h"

using namespace std;

// $Date: 2008-12-02 09:59:55 $
// $Author: lrutten $
// $Revision: 1.2 $

class Meting
{
friend class Vaart;
   
private:
   //int npunten;
   //Punt *punten[50];
   vector<Punt *> punten;
   
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

