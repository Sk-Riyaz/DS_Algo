#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct Pair
{
   int start;
   int end;

   Pair(int s, int e)
   {
      start = s;
      end = e;
   }
};

int minSwaps(int arr[], int n, int k)
{
   int minswap = 1000001;
   vector<Pair> grpIndexes;

   int start = -1;
   for( int i = 0; i < n; ++i )
   {
      if( arr[i] >= k )
      {
         if( start == -1 )
            start = i;
      }
      else if( start != -1 )
      {
         grpIndexes.push_back(Pair(start, i));
         start = -1;
      }
   }
   return minswap;
}

int main()
{
   int n, k;
   cin >> n >> k;
   int arr[n];
   for( int i = 0; i < n; ++i )
   {
      cin >> arr[i];
   }
   cout << minSwaps( arr, n, k ) << endl;
}
