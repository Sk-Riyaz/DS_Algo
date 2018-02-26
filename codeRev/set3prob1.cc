#include<stdio.h>
#include<iostream>

using namespace std;

/* Prob:
   Find all circular (clockwise) tours a truck can take to visit all petrol pumps arranged in a circle. Assume:
      1. c[] has distance from each petrol pump to next.
      2. p[] has amount of petrol at every pump.
      3. The truck has to stop at and use all petrol at each pump.
      4. The truck has infinite capacity.
      5. For 1 unit petrol, the truck can go 1 unit of distance.

   Example: N = 4,    c[] = {4, 3, 9, 5},     p[] = {1, 2, 10, 8}
 */

bool tour(const int c[], const int p[], const int size, int pos, int petrol, int left)
{
   if( 0 == left )
      return true;

   if( petrol+p[pos] < c[pos] )
      return false;

   return tour(c, p, size, (pos+1) % size, petrol+p[pos] - c[pos], left-1);
}

int main()
{
   int c[] = {4, 3, 9, 5};
   int p[] = {1, 2, 10, 8};
   int N = sizeof(c) / sizeof(c[0]);
   for( int i = 0; i < N; ++i )
   {
      if(tour(c, p, N, i, 0, N))
         cout << i << endl;
   }
   return 0;
}
