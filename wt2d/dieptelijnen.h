#ifndef DIEPTELIJNEN_H
#define DIEPTELIJNEN_H

#include <vector>

#include <Wt/WPainter>

#include "vaart.h"
#include "zijden.h"
#include "vlak.h"


// 8/11/2016
// L.Rutten

class Vaart;

class Dieptelijnen
{
private:
   Vaart          *vaart;
   Zijden         *zijden;
   double          deltaz;
   std::vector<Vlak *>  vlakken;
   std::vector<Zijde *> vzijden;

public:
   Dieptelijnen(Vaart *v, double dz);
   void maakdieptelijnen();
   void maakzijden();
   void maakvlakken();
   void toon(int d = 0);
   void teken(Wt::WPainter *qp);
};

#endif
