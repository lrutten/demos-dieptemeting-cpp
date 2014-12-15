#include <iostream>
#include "kleurpad.h"

using namespace std;

KleurPad::KleurPad()
{
	r = 0;
	g = 0;
	b = 0;
}

KleurPad::~KleurPad()
{
	for (unsigned int i=0; i<kleuren.size(); i++)
	{
		delete kleuren[i];
	}
}

void KleurPad::voegbij(Kleur *k)
{
	kleuren.push_back(k);
}

void KleurPad::interpoleer(double uu)
{
	cout << "interpoleer " << uu << "\n";
   unsigned int i=0;
   Kleur *ka = kleuren[i];
   Kleur *kb = kleuren[i+1];

   while (i<kleuren.size()-1 && uu > kb->u)
   {
      i++;
   	ka = kleuren[i];
      kb = kleuren[i+1];
   }
	cout << "ka " << ka->u << "kb " << kb->u << "\n";

   // dit is de eigenlijke interpolatie
   double ua = (kb->u - uu)/(kb->u - ka->u);   
   double ub = (uu - ka->u)/(kb->u - ka->u);   
   r = int (kb->r * ub + ka->r * ua);
   g = int (kb->g * ub + ka->g * ua);
   b = int (kb->b * ub + ka->b * ua);
}
