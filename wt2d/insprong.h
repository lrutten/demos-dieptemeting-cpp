#ifndef INSPRONG_H
#define INSPRONG_H

#include <iostream>

// 8/11/2016
// L. Rutten


class Insprong
{
public:
   static void springin(int d)
   {
      for (int i=0; i<d; i++)
      {
         std::cout << "  ";
      }
   }
};

#endif
