#ifndef VLAK_H
#define VLAK_H

#include <vector>

#include <qpainter.h>
#include "driehoek.h"

using namespace std;

// $Date$
// $Author$
// $Revision$


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
