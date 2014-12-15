#ifndef METING_H
#define METING_H

#include <vector>

#include <QtGui>
#include "punt.h"

using namespace std;

// $Date$
// $Author$
// $Revision$

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
   QTreeWidgetItem *maakitem(QTreeWidgetItem *parent);

   double berekenminx();
   double berekenmaxx();
   double berekenminy();
   double berekenmaxy();
   double berekenminz();
   double berekenmaxz();
};

#endif

