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

// Prob: https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0/?ref=self

int main()
{
   int t;
   cin >> t;
   while( t-- )
   {
      string str;
      cin >> str;
      while( str.length() )
      {
         string temp;
         int n = str.length();
         bool exist = false;
         bool oExist = false;
         for( int i = 1; i <= n; ++i )
         {
            if( i == n || str[i] != str[i-1] )
            {
               if( !exist )
                  temp.append( 1, str[i-1] );

               exist = false;
            }
            else
            {
               exist = true;
               oExist = true;
            }
         }

         if( !oExist )
            break;
         str = temp;
      }

      cout << str << endl;
   }
   return 0;
}
