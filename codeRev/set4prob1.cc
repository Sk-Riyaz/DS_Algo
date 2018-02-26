#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

/* Prob:
   Given an array of integers, find max sum of its
   subarrays.
   a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 */

int maxSumSubArray(int arr[], int n, int &start, int &end)
{
   if( 0 == n )
   {
      return 0;
   }

   int globalMaxSum = arr[0];
   int localMaxSum = arr[0];

   int lstart = 0;
   for( int i = 1; i < n; ++i )
   {
      if( localMaxSum + arr[i] > arr[i] )
      {
         localMaxSum += arr[i];
      }
      else
      {
         lstart = i;
         localMaxSum = arr[i];
      }

      if( localMaxSum > globalMaxSum )
      {
         start = lstart;
         end = i;
         globalMaxSum = localMaxSum;
      }
   }
   return globalMaxSum;
}

int main()
{
   int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(arr)/sizeof(arr[0]);
   int startIndex = 0, endIndex = 0;
   cout << maxSumSubArray(arr, n, startIndex, endIndex) << endl;
   cout << "Start: " << startIndex << " End: " << endIndex << endl;
}
