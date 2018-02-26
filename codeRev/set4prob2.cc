#include<stdio.h>
#include<iostream>

using namespace std;

/* Prob:
   Given an array of integers, find length of longest
   increasing subarray.
   a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 */

int longIncreasingSubArray(const int a[], int n, int &start, int &end)
{
   int localLongSubArray = 1;
   int globalLongSubArray = 1;
   int lStart = 0;
   for( int i = 1; i < n; ++i )
   {
      if( a[i-1] < a[i] )
      {
         localLongSubArray += 1;
      }
      else
      {
         lStart = i;
         localLongSubArray = 1;
      }

      if( localLongSubArray > globalLongSubArray )
      {
         start = lStart;
         end = i;
         globalLongSubArray = localLongSubArray;
      }
   }
   return globalLongSubArray;
}

int main()
{
   int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(arr)/sizeof(arr[0]);
   int startIndex = 0, endIndex = 0;
   cout << longIncreasingSubArray(arr, n, startIndex, endIndex) << endl;
   cout << "Start: " << startIndex << " End: " << endIndex << endl;
}
