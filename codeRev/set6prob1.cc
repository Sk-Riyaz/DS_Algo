#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<climits>

using namespace std;

/* Prob:
   Find least number of coins required to achieve a given target.
   A[] = {1, 5, 6, 8}
   Target = 28
 */

int mincoins(int arr[], int n, int target)
{
   vector< vector< int > > C(n+1, vector<int>(target+1, 0));

   for( int i = 0; i <= n; ++i )
   {
      for( int j = 1; j <= target; ++j )
      {
         if( 0 == i )
         {
            C[i][j] = INT_MAX;
         }
         else if( arr[i-1] <= j ) C[i][j] = min(C[i-1][j], 1 + C[i][j-arr[i-1]]);
         else C[i][j] = C[i-1][j];
      }
   }
   return C[n][target];
}

int main()
{
   //int arr[] = {1, 5, 6, 8};
   int arr[] = {1, 3, 4};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << mincoins( arr, n, 6 ) << endl;
   return 0;
}
