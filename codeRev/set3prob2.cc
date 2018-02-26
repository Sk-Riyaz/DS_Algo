#include<stdio.h>
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

#define MAX 19

/* Prob:
   Find if a given black is conquered in the board game Go.
      1. black and white play alternately.
      2. black is conquered if it is (and all its neighboring blacks,
         if any, are also) surrounded by whites or borders of the board.
      3. board size is 19x19
 */

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

bool isBlocked(char arr[MAX][MAX], int n, const int x, const int y)
{
   if( x < 0 || y < 0 || x >= n || y >= n || arr[x][y] != 'B' )
      return true;

   vector< vector< bool > > visited(n, vector<bool>(n, false));

   deque< Pair >q;
   q.push_back(Pair(x, y));

   bool result = true;
   while( !q.empty() )
   {
      int a = q.back().x;
      int b = q.back().y;
      visited[a][b] = true;
      q.pop_back();

      if( arr[a][b] == ' ' )
      {
         cout << a << " " << b << endl;
         return false;
      }

      if( a+1 < n && !visited[a+1][b] && arr[a+1][b] != 'W' )
         q.push_back( Pair(a+1, b) );

      if( a-1 >= 0 && !visited[a-1][b] && arr[a-1][b] != 'W' )
         q.push_back( Pair(a-1, b) );

      if( b+1 < n && !visited[a][b+1] && arr[a][b+1] != 'W' )
         q.push_back( Pair(a, b+1) );

      if( b-1 >= 0 && !visited[a][b-1] && arr[a][b-1] != 'W' )
         q.push_back( Pair(a, b-1) );
   }

   return result;
}

int main()
{
   char arr[][19] = {
      "WBW ",
      "WBW ",
      "WBW ",
      "WBW "
   };
   cout << isBlocked(arr, 4, 0, 1) << endl;
   return 0;
}
