# $Date: 2008-12-03 16:12:40 $
# $Author: lrutten $
# $Revision: 1.3 $

dieptemeting: dieptemeting.o vaart.o meting.o punt.o strook.o driehoek.o zijden.o zijde.o dieptelijnen.o vlak.o
	g++ -o dieptemeting dieptemeting.o vaart.o meting.o punt.o strook.o driehoek.o zijden.o zijde.o dieptelijnen.o vlak.o -L/usr/lib/qt/lib -lqt-mt


dieptemeting.o: dieptemeting.cpp vaart.h meting.h punt.h strook.h driehoek.h
	g++ -c -g dieptemeting.cpp         
      
vaart.o: vaart.cpp vaart.h meting.h punt.h strook.h driehoek.h zijden.h zijde.h
	g++ -c -g vaart.cpp

meting.o: meting.cpp meting.h punt.h
	g++ -c -g meting.cpp

punt.o: punt.cpp punt.h
	g++ -c -g punt.cpp
      
strook.o: strook.cpp meting.h punt.h strook.h driehoek.h
	g++ -c -g strook.cpp

driehoek.o: driehoek.cpp punt.h driehoek.h
	g++ -c -g driehoek.cpp

zijden.o: zijden.cpp zijde.h 
	g++ -c -g zijden.cpp

zijde.o: zijde.cpp zijde.h 
	g++ -c -g zijde.cpp

dieptelijnen.o: dieptelijnen.cpp dieptelijnen.h 
	g++ -c -g dieptelijnen.cpp

vlak.o: vlak.cpp vlak.h 
	g++ -c -g vlak.cpp


