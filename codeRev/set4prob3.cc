#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* Prob:
   Given an array of integers, find length of longest
   increasing subsequence.
   a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 */

int liss(const int a[], int n)
{
   if( 0 == n ) return 0;

   vector< int >maxSS(n, 1);
   int globalMax = 0;
   for( int i = 1; i < n; ++i )
   {
      int localMax = 0;
      for( int j = 0; j < i; ++j )
      {
         if( a[i] > a[j] )
         {
            localMax = max(localMax, maxSS[j]);
         }
      }
      maxSS[i] += localMax;
      globalMax = max( globalMax, maxSS[i] );
   }
   return globalMax;
}

int main()
{
   //int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int a[] = {86, 177, 115, 193, 135, 186, 92, 49, 21, 162, 27, 90, 59, 163, 126, 140, 26, 172, 136, 11, 168, 167, 29, 182, 130, 62, 123, 67, 135, 129, 2, 22, 58, 69, 167, 193, 56, 11, 42, 29, 173, 21, 119, 184, 137, 198, 124, 115, 170, 13, 126, 91, 180, 156, 73, 62, 170, 196, 81, 105, 125, 84, 127, 136, 105, 46, 129, 113, 57, 124, 95, 182, 145, 14, 167, 34, 164, 43, 150, 87, 8, 76, 178};
   int n = sizeof(a)/sizeof(a[0]);
   cout << liss(a, n) << endl;
   return 0;
}
