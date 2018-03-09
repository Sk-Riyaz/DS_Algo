#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void print( vector< int > v )
{
   for( int i = 0; i < v.size( ); ++i )
   {
      cout << v[i] << " ";
   }
   cout << endl;
}

void printPascal( int n )
{
   vector< int > prev;
   prev.push_back( 1 );
   for( int i = 1; i <= n; ++i )
   {
      print( prev );
      vector< int > cur;
      for( int j = 0; j <= i; ++j )
      {
         if( 0 == j || j == i )
         {
            cur.push_back( 1 );
         }
         else
         {
            cur.push_back( prev[j] + prev[j-1] );
         }
      }
      prev = cur;
   }
}

int main()
{
   int n;
   cin >> n;
   printPascal(n);
   return 0;
}
