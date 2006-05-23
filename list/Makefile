# $Date: 2006-05-23 14:20:18 $
# $Author: lrutten $
# $Revision: 1.1 $

dieptemeting: dieptemeting.o vaart.o meting.o punt.o strook.o driehoek.o
	g++ -o dieptemeting dieptemeting.o vaart.o meting.o punt.o strook.o driehoek.o -L/usr/lib/qt/lib -lqt-mt


dieptemeting.o: dieptemeting.cpp vaart.h meting.h punt.h strook.h driehoek.h
	g++ -c -g dieptemeting.cpp         
      
vaart.o: vaart.cpp vaart.h meting.h punt.h strook.h driehoek.h
	g++ -c -g vaart.cpp

meting.o: meting.cpp meting.h punt.h
	g++ -c -g meting.cpp

punt.o: punt.cpp punt.h
	g++ -c -g punt.cpp
      
strook.o: strook.cpp meting.h punt.h strook.h driehoek.h
	g++ -c -g strook.cpp

driehoek.o: driehoek.cpp punt.h driehoek.h
	g++ -c -g driehoek.cpp

