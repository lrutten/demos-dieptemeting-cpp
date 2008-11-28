#ifndef STROOK_H
#define STROOK_H

#include <qpainter.h>
#include "driehoek.h"

// $Date: 2008-11-28 15:20:56 $
// $Author: lrutten $
// $Revision: 1.1 $


class Strook
{
private:
   int ndriehoeken;
   Driehoek *driehoeken[200];
   
public:
   Strook();
   void voegdriehoekbij(Driehoek *d);
   void toon(int d = 0);
   void teken(QPainter *qp, double minz, double maxz);
};

#endif
