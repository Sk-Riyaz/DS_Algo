#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

/* Prob:
   Find edit distance between two given strings. ABCED and ACEB
 */

int min(int a, int b, int c)
{
   return min( a, min(b, c) );
}

// Recursion - Naive approach
int minEditDist(string str1, string str2)
{
   if( str1.empty() ) return str2.length();
   if( str2.empty() ) return str1.length();

   if( str1[0] == str2[0] )
      return minEditDist(str1.substr(1), str2.substr(1));

   return 1 + min(
         minEditDist(str1.substr(1), str2.substr(1)), // XABC, YABC replace X with Y
         minEditDist(str1.substr(1), str2),  // XABC, ABC remove X
         minEditDist(str1, str2.substr(1))); // ABC, YABC add Y
}

int minEditDistDP(string str1, string str2)
{
   int m = str1.length();
   int n = str2.length();

   vector< vector< int > > E(m+1, vector<int>(n+1, 0));

   for( int i = 0; i <= m; ++i )
   {
      for( int j = 0; j <= n; ++j )
      {
         if( 0 == i )
            E[i][j] = j;
         else if( 0 == j )
            E[i][j] = i;
         else if( str1[i-1] == str2[j-1] )
            E[i][j] = E[i-1][j-1];
         else
            E[i][j] = 1 + min(E[i-1][j-1], E[i][j-1], E[i-1][j]);
      }
   }
   return E[m][n];
}

int main()
{
   cout << minEditDist("XABC", "YABC") << endl;
   cout << minEditDist("ABCED", "ACEB") << endl;
   cout << minEditDistDP("ABCED", "ACEB") << endl;
   cout << minEditDistDP("XABC", "YABC") << endl;
   return 0;
}
