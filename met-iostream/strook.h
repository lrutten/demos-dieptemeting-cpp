#ifndef STROOK_H
#define STROOK_H

#include <qpainter.h>
#include "meting.h"
#include "driehoek.h"

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $


class Strook
{
public:
   int ndriehoeken;
   Driehoek *driehoeken[200];
   Meting *m1;
   Meting *m2;
   
public:
   Strook(Meting *mm1, Meting *mm2);
   void voegdriehoekbij(Driehoek *d);
   void toon(int d = 0);
   void teken(QPainter *qp, double minz, double maxz);
   Driehoek *zoek(double x, double y);
};

#endif
