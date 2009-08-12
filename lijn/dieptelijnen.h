#ifndef DIEPTELIJNEN_H
#define DIEPTELIJNEN_H

#include <vector>

#include <qpainter.h>
#include "vaart.h"
#include "zijden.h"
#include "vlak.h"

using namespace std;

// $Date$
// $Author$
// $Revision$

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
