#ifndef ZIJDEN_H
#define ZIJDEN_H

#include <map>

#include "alles.h"

#include "punt.h"
#include "driehoek.h"
#include "zijde.h"

// 7/11/2016
// L. Rutten

class Driehoek;

class Zijden
{
friend class Dieptelijnen;

private:
   //map<Punt *, map<Punt *,Zijde *> > zijden;
   std::map<std::pair<Punt *,Punt *>, Zijde *> zijden;
   
public:
   Zijden();
   void voegdriehoekbij(Driehoek *d);
   Zijde *zoek(Punt *p1, Punt *p2);
   Zijde *voegzijdebij(Punt *p1, Punt *p2);
   void toon(int d = 0);
};

#endif
