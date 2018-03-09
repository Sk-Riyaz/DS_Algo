#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/last-non-zero-digit-in-factorial/0

int nonZeroFact( int n, bool d = true )
{
   if( n <= 4 )
   {
      int _fact = 1;
      for( int i = 2; i <= n; ++i )
         _fact *= i;
      if( d )
         return _fact % 10;
      else
         return _fact;
   }

   int A = n / 5;
   int B = n % 5;

   int val = pow(2, A) * nonZeroFact( A, false ) * nonZeroFact( B, false );

   while( val )
   {
      if( val % 10 )
         return val % 10;
      val /= 10;
   }
   return val % 10;
}

int main()
{
   int T;
   cin >> T;
   while( T-- )
   {
      int n;
      cin >> n;
      cout << nonZeroFact( n ) << endl;
   }
   return 0;
}
