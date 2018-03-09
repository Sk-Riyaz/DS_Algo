#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order/0

void print( int a[], int n )
{
   for( int i = 0; i < n; ++i )
   {
      cout << a[i];
   }
   cout << " ";
}

void recur( int a[], int n, int i, int prev )
{
   if( i >= n )
   {
      print(a,n);
      return;
   }
   a[i] = prev + 1;
   while( a[i] <= 10 - n + i )
   {
      recur( a, n, i+1, a[i] );
      a[i]++;
   }
}

int main()
{
   int T;
   cin >> T;
   while( T-- )
   {
      int n;
      cin >> n;
      int a[n];
      for( int i = 0; i < n; ++i )
         a[i] = 0;
      recur( a, n, 0, 0 );
      cout << endl;
   }
   return 0;
}
