#ifndef INSPRONG_H
#define INSPRONG_H

// $Date: 2006-05-23 14:20:18 $
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
