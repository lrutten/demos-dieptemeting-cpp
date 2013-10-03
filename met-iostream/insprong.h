#ifndef INSPRONG_H
#define INSPRONG_H

// $Date: 2009-08-12 12:15:37 +0200 (Wed, 12 Aug 2009) $
// $Author: lrutten $
// $Revision: 2355 $

#include <iostream>

using namespace std;

class Insprong
{
public:
   static void springin(int d)
   {
      for (int i=0; i<d; i++)
      {
         cout << "  ";
      }
   }
};

#endif
