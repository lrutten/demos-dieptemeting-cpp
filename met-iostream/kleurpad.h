#ifndef KLEURPAD_H
#define KLEURPAD

#include <vector>

using namespace std;

class Kleur
{
public:
	double u;
	int r;
	int g;
	int b;
	
	Kleur(double uu, int rr, int gg, int bb) :
	      u(uu), r(rr), g(gg), b(bb)
	{
	}
};

class KleurPad
{
private:
	vector<Kleur *> kleuren;
	int             r;
	int             g;
	int             b;
	
public:
   KleurPad();
   ~KleurPad();
   void voegbij(Kleur *k);
   void interpoleer(double uu);
   double getr()
   {
      return r;
   }
   double getg()
   {
      return g;
   }
   double getb()
   {
      return b;
   }
};

#endif
