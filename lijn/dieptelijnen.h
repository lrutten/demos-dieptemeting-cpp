#ifndef DIEPTELIJNEN_H
#define DIEPTELIJNEN_H

#include <vector>

#include <qpainter.h>
#include "vaart.h"
#include "zijden.h"
#include "vlak.h"

using namespace std;

// $Date: 2008-12-04 09:36:02 $
// $Author: lrutten $
// $Revision: 1.3 $

class Vaart;

class Dieptelijnen
{
private:
   Vaart          *vaart;
   Zijden         *zijden;
   double          deltaz;
   vector<Vlak *>  vlakken;
   vector<Zijde *> vzijden;

public:
   Dieptelijnen(Vaart *v, double dz);
   void maakdieptelijnen();
   void maakzijden();
   void maakvlakken();
   void toon(int d = 0);
   void teken(QPainter *qp);
};

#endif
