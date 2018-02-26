#include<stdio.h>
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/number-of-paths/0/?ref=self

struct pos
{
   int row;
   int col;

   pos( int x, int y )
   {
      row = x;
      col = y;
   }

   bool operator==(const pos &rhs) const
   {
      return (this->row == rhs.row-1 && this->col == rhs.col-1);
   }
};

int findThePath( const pos src, const pos dst )
{
   int allSteps = 0;
   vector< vector< bool > > visited(dst.row, vector<bool>(dst.col, false));
   deque< pos > q;
   q.push_back( src );
   while( !q.empty() )
   {
      const pos cur = q.front();
      q.pop_front();

      int a = cur.row;
      int b = cur.col;

      if( cur == dst )
      {
         allSteps += 1;
      }
      visited[a][b] = true;

      if( a+1 < dst.row && !visited[a+1][b] )
         q.push_back( pos(a+1, b) );

      if( b+1 < dst.col && !visited[a][b+1] )
         q.push_back( pos(a, b+1) );
   }
   return allSteps;
}

int main()
{
   int T;
   cin >> T;
   while( T-- )
   {
      int n, m;
      cin >> n >> m;
      std::cout << findThePath( pos(0, 0), pos(n, m) ) << endl;
   }
   return 0;
}
