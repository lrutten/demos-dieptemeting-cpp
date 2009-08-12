#ifndef ZIJDEN_H
#define ZIJDEN_H


//#include <vector>
#include <map>

#include "alles.h"

#include "punt.h"
#include "driehoek.h"
#include "zijde.h"

using namespace std;

// $Date$
// $Author$
// $Revision$

class Driehoek;

class Zijden
{
friend class Dieptelijnen;

private:
   //vector<Zijde *> zijden;
   map<Punt *, map<Punt *,Zijde *> > zijden;
   
public:
   Zijden();
   //void voegzijdebij(Zijde *z);
   void voegdriehoekbij(Driehoek *d);
   Zijde *zoek(Punt *p1, Punt *p2);
   Zijde *voegzijdebij(Punt *p1, Punt *p2);
   void toon(int d = 0);
};

#endif
