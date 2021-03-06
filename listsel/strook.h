#ifndef STROOK_H
#define STROOK_H

#include <QtGui>
#include <Qt3Support/Q3ListView>
#include <Qt3Support/Q3ListViewItem>

#include "meting.h"
#include "driehoek.h"

// $Date$
// $Author$
// $Revision$


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
   Q3ListViewItem *maakitem(Q3ListViewItem *parent);
};

#endif
