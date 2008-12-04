#ifndef VLAK_H
#define VLAK_H

#include <vector>

#include <qpainter.h>
#include "driehoek.h"

using namespace std;

// $Date: 2008-12-04 16:30:27 $
// $Author: lrutten $
// $Revision: 1.2 $


class Vlak
{
friend class Dieptelijnen;
friend class Zijde;

private:
   double z;

public:
   Vlak(double iz);
   void toon(int d = 0);
};

#endif
