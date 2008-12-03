#ifndef VLAK_H
#define VLAK_H

#include <vector>

#include <qpainter.h>
#include "driehoek.h"

using namespace std;

// $Date: 2008-12-03 16:12:40 $
// $Author: lrutten $
// $Revision: 1.1 $


class Vlak
{
friend class Dieptelijnen;

private:
   double z;

public:
   Vlak(double iz);
   void toon(int d = 0);
};

#endif
