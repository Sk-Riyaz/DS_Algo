#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

/* Prob:
   Rod cutting problem.
   Given a rod of length L and values of chunks of sizes <= L, determine the
   maximum value obtainable by cutting up the rod to sell as chunks.
   val[] = {2, 3, 8, 10, 12, 13};
   cnk[] = {1, 2, 3, 4, 5, 6};
   L = 10
 */

int rodCut(int cnk[], int val[], int L, int n)
{
   vector< vector< int > >LL( n+1, vector< int >(L+1, 0) );
   for( int i = 1; i <= n; ++i )
   {
      for( int j = 1; j <= L; ++j )
      {
         if( cnk[i-1] <= j )
         {
            LL[i][j] = max( LL[i-1][j], val[i-1] + LL[i][j-cnk[i-1]] );
         }
         else
         {
            LL[i][j] = LL[i-1][j];
         }
      }
   }
   int i = n, j = L;
   while( i > 0 || j > 0 )
   {
      if( LL[i][j] != LL[i-1][j] )
      {
         cout << i << " ";
         j = j - cnk[i-1];
      }
      else
         i -= 1;
   }
   cout << endl;
   return LL[n][L];
}

int main( )
{
   int l[] = {1, 2, 3, 4, 5, 6};
   int val[] = {2, 3, 8, 10, 12, 13};
   int L = 10;
   int n = sizeof(l)/sizeof(l[0]);
   cout << rodCut( l, val, L, n ) << endl;
   return 0;
}
