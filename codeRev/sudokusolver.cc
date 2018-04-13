#include<bits/stdc++.h>

using namespace std;

bool solve( int arr[9][9], int i, int j, int val )
{
   for( int k = 0; k < 9; ++k )
      if( arr[i][k] == val ) return true;

   for( int k = 0; k < 9; ++k )
      if( arr[k][j] == val ) return true;

   int is = i - (i%3);
   int iE = i + (3- (i%3));

   int js = j - (j%3);
   int jE = j + (3- (j%3));

   for( int k = is; k < iE; ++k )
      for( int l = js; l < jE; ++l )
         if( arr[k][l] == val ) return true;
   return false;
}

bool solver( int arr[9][9], int i, int j )
{
   if( 9 == i ) return true;
   while( j < 9 && arr[i][j] != 0 ) ++j;
   if( 9 <= j ) return solver( arr, i+1, 0 );

   for( int val = 1; val <= 9; ++val )
   {
      bool exist = solve(arr, i, j, val);
      if( !exist )
      {
         arr[i][j] = val;
         bool bVal = solver( arr, i, j+1 );
         if( !bVal )
         {
            arr[i][j] = 0;
         }
         else
            return true;
      }
   }
   return false;
}

int main()
{
   int T;
   cin >> T;
   while(T--)
   {
      int arr[9][9];
      for( int i = 0; i < 9; ++i )
         for( int j = 0; j < 9; ++j )
            cin >> arr[i][j];

      solver( arr, 0, 0 );

      for( int i = 0; i < 9; ++i )
      {
         for( int j = 0; j < 9; ++j )
            cout << arr[i][j] << " ";
         cout << endl;
      }
   }
   return 0;
}
