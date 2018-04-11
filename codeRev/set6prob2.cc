#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

/* Prob:
   0/1 Knapsack.
   Given integer weights and values of N items, choose items with overall
   weight <= W to get maximum value in the knapsack.
   val[]= {2, 3, 8, 10, 12, 13};
   wt[] = {1, 2, 3, 4, 5, 6};
   W = 10
 */

int knapSack( int wt[], int val[], int W, int n )
{
   vector< vector< int > >K( n+1, vector< int >(W+1, 0) );

   for( int i = 1; i < n+1; ++i )
   {
      for( int j = 1; j < W+1; ++j )
      {
         if( wt[i-1] <= j )
         {
            K[i][j] = max( val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j] );
         }
         else
         {
            K[i][j] = K[i-1][j];
         }
      }
   }

   int i = n, j = W;
   while( i > 0 || j > 0 )
   {
      if( K[i][j] != K[i-1][j] )
      {
         cout << i << " ";
         j = j - wt[i-1];
      }
      i -= 1;
   }
   cout << endl;
   return K[n][W];
}

int main()
{
   //int wt[] = {1, 2, 3, 4, 5, 6};
   //int val[] = {2, 3, 8, 10, 12, 13};
   int wt[] = {6, 5, 4, 3, 2, 1};
   int val[] = {13, 12, 10, 8, 3, 2};
   int W = 10;
   int n = sizeof(wt)/sizeof(wt[0]);
   cout << knapSack( wt, val, W, n ) << endl;
   return 0;
}
