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
   int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   cout << liss(a, n) << endl;
   return 0;
}
