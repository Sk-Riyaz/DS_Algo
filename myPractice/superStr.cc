#include<stdio.h>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<deque>
#include<climits>

#define FOR(j, n) for(int i = j; i < n; ++i )

using namespace std;

// Prob: https://www.hackerrank.com/challenges/reduced-string/problem

int main()
{
   string str;
   cin >> str;
   while( str.length() )
   {
      string temp;
      int n = str.length();
      bool exist = false;
      for( int i = 1; i <= n; ++i )
      {
         if( i == n || str[i] != str[i-1] )
         {
            temp.append( 1, str[i-1] );
         }
         else
         {
            ++i;
            exist = true;
         }
      }

      if( !exist )
         break;
      str = temp;
   }

   if( str.length( ) )
      cout << str << endl;
   else
      cout << "Empty String" << endl;
   return 0;
}
