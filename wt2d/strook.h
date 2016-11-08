#ifndef STROOK_H
#define STROOK_H

#include <vector>

#include <Wt/WPainter>
#include "driehoek.h"


// 8/11/2016
// L. Rutten

class Strook
{
friend class Vaart;
friend class Dieptelijnen;

private:
   std::vector<Driehoek *> driehoeken;
   
public:
   Strook();
   void voegdriehoekbij(Driehoek *d);
   void toon(int d = 0);
   void teken(Wt::WPainter *qp, double minz, double maxz);
   void dumpobj(FILE *fp);
};

#endif
