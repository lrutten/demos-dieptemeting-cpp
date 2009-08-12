#ifndef DRIEHOEK_H
#define DRIEHOEK_H

#include <qpainter.h>
#include "punt.h"

// $Date$
// $Author$
// $Revision$


class Driehoek
{
public:
   Punt *p1;
   Punt *p2;
   Punt *p3;

   bool omuis;
   bool selectie;
   
   Driehoek(Punt *ip1, Punt *ip2, Punt *p3);
   void toon(int d = 0);
   void teken(QPainter *qp, double minz, double maxz);
   
   void setomuis(bool b)
   {
      omuis = b;
   }
   void setselectie(bool b)
   {
      selectie = b;
   }
   
};

#endif

