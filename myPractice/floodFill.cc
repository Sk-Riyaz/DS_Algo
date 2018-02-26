#include<stdio.h>
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

struct Pair
{
   int x;
   int y;

   Pair(int x, int y)
   {
      this->x = x;
      this->y = y;
   }
};

void fill(vector< vector < int > >&arr, int x, const int y, const int K)
{
   const int n = arr.size();
   const int m = arr[0].size();
   const int r = arr[x][y];
   vector< vector< bool > > visited(n, vector<bool>(m, false));
   deque< Pair >q;
   q.push_back(Pair(x, y));

   bool result = true;
   while( !q.empty() )
   {
      int a = q.back().x;
      int b = q.back().y;
      visited[a][b] = true;
      arr[a][b] = K;
      q.pop_back();

      if( a+1 < n && !visited[a+1][b] && arr[a+1][b] == r )
         q.push_back( Pair(a+1, b) );

      if( a-1 >= 0 && !visited[a-1][b] && arr[a-1][b] == r )
         q.push_back( Pair(a-1, b) );

      if( b+1 < m && !visited[a][b+1] && arr[a][b+1] == r )
         q.push_back( Pair(a, b+1) );

      if( b-1 >= 0 && !visited[a][b-1] && arr[a][b-1] == r )
         q.push_back( Pair(a, b-1) );
   }
}

int main()
{
   int T;
   cin >> T;
   while( T-- )
   {
      int n, m;
      cin >> n >> m;
      vector< vector < int > >arr(n, vector< int >(m, 0));
      for( int i = 0; i < n; ++i )
      {
         for( int j = 0; j < m; ++j )
            cin >> arr[i][j];
      }

      int x, y, K;
      cin >> x >> y >> K;

      fill(arr, x, y, K);
      for( int i = 0; i < n; ++i )
      {
         for( int j = 0; j < m; ++j )
            cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
