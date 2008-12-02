#ifndef DRIEHOEK_H
#define DRIEHOEK_H

#include <qpainter.h>
#include "punt.h"
#include "zijde.h"

// $Date: 2008-12-02 09:59:55 $
// $Author: lrutten $
// $Revision: 1.2 $


class Driehoek
{
friend class Zijden;

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

