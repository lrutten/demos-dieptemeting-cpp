#ifndef VLAK_H
#define VLAK_H

#include <vector>

#include <qpainter.h>
#include "driehoek.h"


// 7/11/2016
// L. Rutten

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
