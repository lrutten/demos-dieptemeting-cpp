#include <iostream>
#include <fstream>
#include <sstream>
#include "vaart.h"
#include "insprong.h"

using namespace std;

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $

Vaart::Vaart()
{
   nmetingen = 0;
   nstroken = 0;
   
   minx = 0.0;
   maxx = 0.0;
   miny = 0.0;
   maxy = 0.0;
   minz = 0.0;
   maxz = 0.0;
}

void Vaart::voegmetingbij(Meting *m)
{
   metingen[nmetingen++] = m;  
}

void Vaart::voegstrookbij(Strook *s)
{
   stroken[nstroken++] = s;  
}

void Vaart::toon(int d)
{
   Insprong::springin(d);
   cout << "Vaart\n";

   Insprong::springin(d);
   cout << "minx %lf\n" << minx;
   Insprong::springin(d);
   cout << "maxx %lf\n" << maxx;

   Insprong::springin(d);
   cout << "miny %lf\n" << miny;
   Insprong::springin(d);
   cout << "maxy %lf\n" << maxy;

   Insprong::springin(d);
   cout << "minz %lf\n" << minz;
   Insprong::springin(d);
   cout << "maxz %lf\n" << maxz;

   for (int i = 0; i<nmetingen; i++)
   {
      metingen[i]->toon(d + 1);
   }
   for (int i = 0; i<nstroken; i++)
   {
      stroken[i]->toon(d + 1);
   }
}

bool Vaart::isleeg(const string &bf)
{
	return bf.empty();
}


int Vaart::naarint(const string &s)
{
   int n;

   istringstream(s) >> n;
   return n;
}

double Vaart::naardouble(const string &s)
{
   double d;

   istringstream(s) >> d;
   return d;
}

void Vaart::leesbestand(const char *naam)
{
   string  lijn;
   ifstream fin;

   fin.open(naam);
   if(!fin.is_open())
   {
      cout << "Fout bij inlezing !\n";
      //exit(1);
   }

   for(int i=0;i<8;i++)
   {
      getline(fin, lijn);
   }

   getline(fin, lijn);
   while(!fin.eof())
   {
      if(isleeg(lijn))
      {
         continue;
      }
      cout << lijn << "\n";

      // maak een stream van de string
      stringstream strstr(lijn);

      // gebruik stream iterators om de stream als witruimte-gescheiden strings naar een vector
      // te kopieren
      istream_iterator<string> it(strstr);
      istream_iterator<string> end;
      vector<string> woorden(it, end);
      
      // Geef alle woorden weer 
      for (unsigned int i=0; i<woorden.size(); i++)
      {
         cout << "   " << woorden[i] << "\n";
      }

      int aantal = naarint(woorden[0]);
      cout << "aantal "<< aantal << "\n";

      double x = naardouble(woorden[3]);
      cout << "x "<< x << "\n";

      double y = naardouble(woorden[4]);
      cout << "y "<< y << "\n";

      x *= 10000;
      y *= 10000;
      
      Meting *m = new Meting();
      int i=0;
      for (unsigned int pos = 5; pos<woorden.size(); pos++)
      {
         int z = naarint(woorden[pos]);
         cout << "z "<< z << "\n";

         Punt *p = new Punt(x, y+i*6, z*10);
         m->voegpuntbij(p);
	 i++;
      }
      voegmetingbij(m);

      getline(fin, lijn);
   }
   cout << "Gelezen!\n";
}


void Vaart::maakstroken()
{
   for (int im = 0; im < nmetingen - 1; im++)
   {
      Meting *m1 = metingen[im];
      Meting *m2 = metingen[im + 1];
      
      Strook *s = new Strook(m1, m2);
      voegstrookbij(s);
      
      for (int ip = 0; ip < m1->npunten - 1; ip++)
      {
         Punt *p1 = m1->punten[ip];
         Punt *p2 = m1->punten[ip + 1];
         Punt *p3 = m2->punten[ip + 1];
         Punt *p4 = m2->punten[ip];
         
         s->voegdriehoekbij(new Driehoek(p1, p2, p4));
         s->voegdriehoekbij(new Driehoek(p2, p3, p4));
      }
   }
}

void Vaart::berekenminmax()
{
   minx = metingen[0]->berekenminx();
   for (int i = 1; i<nmetingen; i++)
   {
      double temp = metingen[i]->berekenminx();
      
      if (temp < minx)
      {
         minx = temp;
      }
   }

   maxx = metingen[0]->berekenmaxx();
   for (int i = 1; i<nmetingen; i++)
   {
      double temp = metingen[i]->berekenmaxx();
      
      if (temp > maxx)
      {
         maxx = temp;
      }
   }

   miny = metingen[0]->berekenminy();
   for (int i = 1; i<nmetingen; i++)
   {
      double temp = metingen[i]->berekenminy();
      
      if (temp < miny)
      {
         miny = temp;
      }
   }

   maxy = metingen[0]->berekenmaxy();
   for (int i = 1; i<nmetingen; i++)
   {
      double temp = metingen[i]->berekenmaxy();
      
      if (temp > maxy)
      {
         maxy = temp;
      }
   }
   
   
   minz = metingen[0]->berekenminz();
   for (int i = 1; i<nmetingen; i++)
   {
      double temp = metingen[i]->berekenminz();
      
      if (temp < minz)
      {
         minz = temp;
      }
   }

   maxz = metingen[0]->berekenmaxz();
   for (int i = 1; i<nmetingen; i++)
   {
      double temp = metingen[i]->berekenmaxz();
      
      if (temp > maxz)
      {
         maxz = temp;
      }
   }
}

Driehoek *Vaart::zoek(double x, double y)
{
   Driehoek *ds = NULL;
   for (int i=0; i<nstroken; i++)
   {
      ds = stroken[i]->zoek(x, y);
      if (ds != NULL)
      {
         return ds;
      }
   }
   return ds;
}
