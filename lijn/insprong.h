#ifndef INSPRONG_H
#define INSPRONG_H

// $Date: 2008-11-28 15:20:56 $
// $Author: lrutten $
// $Revision: 1.1 $


class Insprong
{
public:
   static void springin(int d)
   {
      for (int i=0; i<d; i++)
      {
         printf("  ");
      }
   }
};

#endif
