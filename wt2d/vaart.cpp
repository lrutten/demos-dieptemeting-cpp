#include <iostream>
#include <future>
#include <stdio.h>

#include "vaart.h"
#include "insprong.h"

// 8/11/2016
// L. Rutten

Vaart::Vaart()
{
   minx = 0.0;
   maxx = 0.0;
   miny = 0.0;
   maxy = 0.0;
   minz = 0.0;
   maxz = 0.0;
   
   dieptelijnen = new Dieptelijnen(this, 50.0);
}

void Vaart::voegmetingbij(Meting *m)
{
   metingen.push_back(m);  
}

void Vaart::voegstrookbij(Strook *s)
{
   stroken.push_back(s);  
}

void Vaart::toon(int d)
{
   Insprong::springin(d);
   std::cout << "Vaart\n";

   Insprong::springin(d);
   std::cout << "minx " << minx << "\n";
   Insprong::springin(d);
   std::cout << "maxx " << maxx << "\n";

   Insprong::springin(d);
   std::cout << "miny " << miny << "\n";
   Insprong::springin(d);
   std::cout << "maxy " << maxy << "\n";

   Insprong::springin(d);
   std::cout << "minz " << minz << "\n";
   Insprong::springin(d);
   std::cout << "maxz " << maxz << "\n";


   /*
   for (int i = 0; i<metingen.size(); i++)
   {
      metingen[i]->toon(d + 1);
   }
   for (int i = 0; i<stroken.size(); i++)
   {
      stroken[i]->toon(d + 1);
   }
   */
   dieptelijnen->toon(d + 1);
}

void Vaart::dumpobj(const char *bestand)
{
   FILE *fp = fopen(bestand, "w");
   if (fp != NULL)
   {
      // dump alle punten
      for (unsigned int im=0; im < metingen.size(); im++)
      {
         Meting *m = metingen[im];
         for (unsigned int ip=0; ip<m->punten.size(); ip++)
         {
            Punt *p = m->punten[ip];
            fprintf(fp, "v %lf %lf %lf\n", p->x, p->y, p->z);
         }
      }

      // dump alle driehoeken
      for (unsigned int is=0; is < stroken.size(); is++)
      {
         Strook *s = stroken[is];
         for (unsigned int id=0; id < s->driehoeken.size(); id++)
         {
            Driehoek *d = s->driehoeken[id];
            fprintf(fp,"f %d %d %d\n", d->p1->nr, d->p2->nr, d->p3->nr); 
         }
      }
      fclose(fp);
   }
   else
   {
      printf("bestand niet geschreven\n");
   }
}

int Vaart::isleeg(char *bf)
{
	int ntekens = 0;
	while (*bf != '\0')
	{
		if (*bf != ' ' && *bf != '\n' && *bf != '\t')
			ntekens++;
		bf++;
	}
	return ntekens == 0;
}


#define SENSORBREEDTE 60
#define ZFACTOR        1


// deze functie is overgenomen van Jo Vliegen

void Vaart::leesbestand(const char *naam)
{
	char buf[1000];
	FILE *f;
	int i,n,temp;
	float x,y;
	int xx,yy;

	f=fopen(naam,"r");
	if(f==NULL)
	{
		printf("\nFout bij inlezing !\n\n");
		//exit(1);
	}

	for(i=0;i<8;i++)
	{
		fgets(buf,1000,f);
	}

   fgets(buf,1000,f);
	while(!feof(f))
	{
		if(isleeg(buf))
			continue;

		Meting *m = new Meting();

		sscanf(buf,"%d",&n);

		sscanf(&buf[25],"%f",&x);xx=(int)(x*10000);
		sscanf(&buf[34],"%f",&y);yy=(int)(y*10000);

		// test n = 10;
		for(i=0;i<n;i++)
		{
			sscanf(&buf[42+(i*4)],"%d",&temp);
         //printf("z %d\n", temp);

			// test if (i > 2)
			// test {
			   Punt *p = new Punt(xx*10,yy+i*SENSORBREEDTE,temp*ZFACTOR);
			   m->voegpuntbij(p);
			// test }
		}

		voegmetingbij(m);

		fgets(buf,1000,f);
	}
}


Strook *Vaart::maakstrook(Meting *m1, Meting *m2)
{
   Strook *s = new Strook();
   voegstrookbij(s);
   
   for (unsigned int ip = 0; ip < m1->punten.size() - 1; ip++)
   {
      Punt *p1 = m1->punten[ip];
      Punt *p2 = m1->punten[ip + 1];
      Punt *p3 = m2->punten[ip + 1];
      Punt *p4 = m2->punten[ip];
      
      Driehoek *d1 = new Driehoek(p1, p2, p4);
      Driehoek *d2 = new Driehoek(p2, p3, p4);

      s->voegdriehoekbij(d1);
      s->voegdriehoekbij(d2);
   }
   return s;
}

/*
    Deze methode verdeelt het werk over meerdere threads.
    Elke thread maakt 1 strook.
 */
void Vaart::maakstroken()
{
   const auto thread_keuze = std::launch::async;
   //const auto thread_keuze = std::launch::deferred;
   
   for (unsigned int im = 0; im < metingen.size() - 1; im++)
   {
      Meting *m1 = metingen[im];
      Meting *m2 = metingen[im + 1];
      
      auto ftr = std::async(thread_keuze,
         [&](Meting *m1, Meting *m2) -> Strook * 
         { 
            return maakstrook(m1, m2); 
         },
         m1, m2);

      Strook *s  = ftr.get();
      voegstrookbij(s);
   }
}



/*
  Deze methode maakt de stroken zonder gebruik te maken
  van de threads.
 
void Vaart::maakstroken()
{
   for (unsigned int im = 0; im < metingen.size() - 1; im++)
   {
      Meting *m1 = metingen[im];
      Meting *m2 = metingen[im + 1];
      
      Strook *s = maakstrook(m1, m2);
      voegstrookbij(s);
   }
}
 */
 
void Vaart::berekenminmax()
{
   minx = metingen[0]->berekenminx();
   for (unsigned int i = 1; i<metingen.size(); i++)
   {
      double temp = metingen[i]->berekenminx();
      
      if (temp < minx)
      {
         minx = temp;
      }
   }

   maxx = metingen[0]->berekenmaxx();
   for (unsigned int i = 1; i<metingen.size(); i++)
   {
      double temp = metingen[i]->berekenmaxx();
      
      if (temp > maxx)
      {
         maxx = temp;
      }
   }

   miny = metingen[0]->berekenminy();
   for (unsigned int i = 1; i<metingen.size(); i++)
   {
      double temp = metingen[i]->berekenminy();
      
      if (temp < miny)
      {
         miny = temp;
      }
   }

   maxy = metingen[0]->berekenmaxy();
   for (unsigned int i = 1; i<metingen.size(); i++)
   {
      double temp = metingen[i]->berekenmaxy();
      
      if (temp > maxy)
      {
         maxy = temp;
      }
   }
   
   
   minz = metingen[0]->berekenminz();
   for (unsigned int i = 1; i<metingen.size(); i++)
   {
      double temp = metingen[i]->berekenminz();
      
      if (temp < minz)
      {
         minz = temp;
      }
   }

   maxz = metingen[0]->berekenmaxz();
   for (unsigned int i = 1; i<metingen.size(); i++)
   {
      double temp = metingen[i]->berekenmaxz();
      
      if (temp > maxz)
      {
         maxz = temp;
      }
   }
}

void Vaart::maakdieptelijnen()
{
   dieptelijnen->maakdieptelijnen();
}
