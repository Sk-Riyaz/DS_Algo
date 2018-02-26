#include<iostream>
#include<stdio.h>

using namespace std;

/* Prob:
   Implement power(x, y)
 */

double powerIter(int x, int y)
{
   double xPowY = 1;
   while( y > 0 )
   {
      if( y % 2 )
      {
         xPowY *= x;
      }
      x *= x;
      y /= 2;
   }
   return xPowY;
}

double power(int x, int y)
{
   if(1 == y)
      return x;

   if(0 == y)
      return 1;

   double temp = power(x, y/2);
   temp *= temp;
   if( 1 == y%2 )
      temp *= x;

   return temp;
}

int main()
{
   cout << power(2, 0) << endl;
   cout << power(2, 1) << endl;
   cout << power(2, 2) << endl;
   cout << power(2, 3) << endl;
   cout << power(2, 5) << endl;
   cout << power(2, 7) << endl;
   cout << power(2, 11) << endl;
   return 0;
}
