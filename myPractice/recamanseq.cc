#include<stdio.h>
#include<iostream>
#include<map>
#include<cstring>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/recamans-sequence/0

int main()
{
   int T;
   cin >> T;
   while(T--)
   {
      int n;
      cin >> n;
      int prev = 0;
      map<int, bool> e;
      for( int i = 1; i <= n; ++i )
      {
         int val = prev - i;
         if( val < 0 || e.find(val) != e.end() )
         {
            val = prev + i;
         }
         cout << prev << " ";
         e[prev] = true;
         prev = val;
      }
      cout << endl;
   }
   return 0;
}
