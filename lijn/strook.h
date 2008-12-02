#ifndef STROOK_H
#define STROOK_H

#include <vector>

#include <qpainter.h>
#include "driehoek.h"

using namespace std;

// $Date: 2008-12-02 10:40:59 $
// $Author: lrutten $
// $Revision: 1.3 $


class Strook
{
friend class Vaart;

private:
   vector<Driehoek *> driehoeken;
   
public:
   Strook();
   void voegdriehoekbij(Driehoek *d);
   void toon(int d = 0);
   void teken(QPainter *qp, double minz, double maxz);
   void dumpobj(FILE *fp);
};

#endif
