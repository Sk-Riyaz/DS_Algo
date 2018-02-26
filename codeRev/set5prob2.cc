#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

/* Prob:
   Find length of longest common substring given two
   strings.
   ABCED and ACEB
 */

int gLCA = 0;

void lca(const string str1, const string str2, int lLCA)
{
   gLCA = max( gLCA, lLCA );
   if( str1.empty() || str2.empty() )
   {
      return;
   }

   if( str1[0] == str2[0] )
   {
      lca( str1.substr(1), str2.substr(1), lLCA+1 );
   }
   else
   {
      lca( str1.substr(1), str2, 0 );
      lca( str1, str2.substr(1), 0 );
   }
}

int lcaDP(const string str1, const string str2)
{
   int m = str1.length(), n = str2.length();
   vector< vector< int > > L(m+1, vector<int>(n+1, 0));
   int maxLCA = 0;
   for( int i = 1; i <= m; ++i )
   {
      for( int j = 1; j <= n; ++j )
      {
         if( str1[i-1] == str2[j-1] )
         {
            L[i][j] = 1 + L[i-1][j-1];
            maxLCA = max( L[i][j], maxLCA );
         }
         else
            L[i][j] = 0;
      }
   }
   return maxLCA;
}

int main()
{
   lca("ABCEB", "ACED", 0);
   cout << gLCA << endl;

   cout << lcaDP("ABCEB", "ACED") << endl;
   return 0;
}
