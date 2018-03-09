#include<stdio.h>
#include<iostream>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/shuffle-integers/0

int main()
{
   int t;
   cin >> t;
   while( t-- )
   {
      int n;
      cin >> n;
      int arr[n];

      for( int i = 0; i < n; ++i )
      {
         cin >> arr[i];
      }

      int a = 0, b = n/2;
      while( a < n/2 && b < n )
      {
         cout << arr[a] << " " << arr[b] << " ";
         ++a;
         ++b;
      }

      if( n % 2 )
         cout << arr[b];
      cout << endl;
   }
   return 0;
}
