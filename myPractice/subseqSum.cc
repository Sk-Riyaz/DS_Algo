#include<stdio.h>
#include<iostream>

using namespace std;

bool sameC( int arr[], int i, int cur, int tot )
{
   if( cur <= tot )
   {
      if( cur == tot )
      {
         return true;
      }
   }
   else
      return false;

   if( i <= 0 )
      return false;

   if( sameC( arr, i-1, cur+arr[i-1], tot-arr[i-1] ) ) return true;
   return sameC( arr, i-1, cur, tot );
}

int main()
{
   int t;
   cin >> t;
   while( t-- )
   {
      int n, m;
      cin >> n >> m;
      int arr[n];
      int sum = 0;
      for( int i = 0; i < n; ++i )
      {
         cin >> arr[i];
         sum += arr[i];
      }

      if( sum == m )
      {
         cout << 1 << endl;
      }
      else if( sum < m || (sum + m)&1)
      {
         cout << 0 << endl;
      }
      else
      {
         sum = (sum-m)/2;
         cout << sameC( arr, n, m, sum ) << endl;
      }
   }
   return 0;
}
