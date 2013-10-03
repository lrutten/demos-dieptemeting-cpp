#ifndef DRIEHOEK_H
#define DRIEHOEK_H

#include <qpainter.h>
#include "punt.h"

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $


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

