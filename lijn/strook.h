#ifndef STROOK_H
#define STROOK_H

#include <vector>

#include <qpainter.h>
#include "driehoek.h"

using namespace std;

// $Date: 2008-12-02 09:59:55 $
// $Author: lrutten $
// $Revision: 1.2 $


class Strook
{
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
