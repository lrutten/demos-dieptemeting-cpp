#ifndef DIEPTELIJNEN_H
#define DIEPTELIJNEN_H

#include <vector>

#include <qpainter.h>
#include "vaart.h"
#include "zijden.h"
#include "vlak.h"

using namespace std;

// $Date: 2008-12-03 16:12:40 $
// $Author: lrutten $
// $Revision: 1.2 $

class Vaart;

class Dieptelijnen
{
private:
   Vaart         *vaart;
   Zijden        *zijden;
   double         deltaz;
   vector<Vlak *> vlakken;

public:
   Dieptelijnen(Vaart *v, double dz);
   void maakdieptelijnen();
   void maakzijden();
   void maakvlakken();
   void toon(int d = 0);
};

#endif
