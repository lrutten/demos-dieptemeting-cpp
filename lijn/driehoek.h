#ifndef DRIEHOEK_H
#define DRIEHOEK_H

#include <qpainter.h>
#include "punt.h"
#include "zijde.h"

// $Date: 2008-12-03 16:12:40 $
// $Author: lrutten $
// $Revision: 1.3 $


class Driehoek
{
friend class Zijden;
friend class Dieptelijnen;

public:
   Punt *p1;
   Punt *p2;
   Punt *p3;
   Zijde *z12;
   Zijde *z23;
   Zijde *z31;
   
   Driehoek(Punt *ip1, Punt *ip2, Punt *p3);
   void toon(int d = 0);
   void teken(QPainter *qp, double minz, double maxz);
   void dumpobj(FILE *fp);
};

#endif

