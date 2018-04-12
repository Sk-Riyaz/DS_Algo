#include<bits/stdc++.h>

using namespace std;

bool nqueens(int n, int r, vector< pair< int, int > > &pos,
      vector< vector< string > > &out )
{
   if( r == n )
   {
      vector< string > inp(n, string(n, '.'));
      for( auto p : pos )
         inp[p.first][p.second] = 'Q';
      out.push_back( inp );
      return true;
   }

   for( int c = 0; c < n; ++c )
   {
      bool colExist = true;
      for( auto p : pos )
      {
         if( c == p.second ||
               r-c == p.first - p.second ||
               r+c == p.first + p.second )
         {
            colExist = false;
            break;
         }
      }

      if( colExist )
      {
         pos.push_back( pair< int, int >(r, c) );
         nqueens( n, r+1, pos, out );
         pos.pop_back();
      }
   }
   return false;
}

int placequeens(int n)
{
   vector< pair< int, int > > pos;
   vector< vector< string > > out;
   nqueens( n, 0, pos, out );
   return 0;
}

int main()
{
   placequeens( 4 );
   return 0;
}
