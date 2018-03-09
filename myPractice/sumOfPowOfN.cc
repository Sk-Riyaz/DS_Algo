#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers/0

int steps = 0;

void possibilities( vector< int > val, const int &x, int i, int sum )
{
   if( x <= sum )
   {
      if( x == sum )
         steps += 1;
      return;
   }

   if( i <= 0 ) return;

   possibilities( val, x, i-1, sum + val[i-1] );
   possibilities( val, x, i-1, sum );
}

int main()
{
   int T;
   cin >> T;
   while( T-- )
   {
      int x, n;
      cin >> x >> n;
      int _pow = 0;
      vector< int > val;
      for( int i = 1; (_pow = pow(i, n)) <= x; ++i )
         val.push_back( _pow );

      steps = 0;
      possibilities( val, x, val.size(), 0 );
      cout << steps << endl;
   }
   return 0;
}
