#ifndef DIEPTELIJNEN_H
#define DIEPTELIJNEN_H

#include <vector>

#include <qpainter.h>
#include "vaart.h"
#include "zijden.h"

using namespace std;

// $Date: 2008-12-03 13:04:22 $
// $Author: lrutten $
// $Revision: 1.1 $

class Vaart;

class Dieptelijnen
{
private:
   Vaart  *vaart;
   Zijden *zijden;
   int     deltaz;

public:
   Dieptelijnen(Vaart *v, int dz);
   void maakdieptelijnen();
   void maakzijden();
   void toon(int d = 0);
};

#endif
