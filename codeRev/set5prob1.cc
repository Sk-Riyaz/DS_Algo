#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

/* Prob:
   Find length of longest common subsequence given
   two strings.
   ABCD and ACEB
 */


int gLSS = 0;

/* Top Down approach */
void lcs(const string str1, const string str2, int lLSS)
{
   if( str1.empty() || str2.empty() )
   {
      gLSS = max( gLSS, lLSS );
      return;
   }

   if( str1[0] == str2[0] )
   {
      lcs(str1.substr(1), str2.substr(1), lLSS+1);
   }
   else
   {
      lcs(str1.substr(1), str2, lLSS);
      lcs(str1, str2.substr(1), lLSS);
   }
}

/* Bottom Up approach */
int lcs(const string str1, const string str2)
{
   if( str1.empty() || str2.empty() )
      return 0;

   if( str1[0] == str2[0] )
      return 1 + lcs(str1.substr(1), str2.substr(1));

   return max( lcs(str1.substr(1), str2), lcs(str1, str2.substr(1)) );
}

int lcsDP(const string str1, const string str2)
{
   int m = str1.length(), n = str2.length();
   vector< vector< int > > lcsArr(m+1, vector<int>(n+1, 0));
   for( int i = 1; i <= m; ++i )
   {
      for( int j = 1; j <= n; ++j )
      {
         if( str1[i-1] == str2[j-1] )
            lcsArr[i][j] = 1+lcsArr[i-1][j-1];
         else
            lcsArr[i][j] = max(lcsArr[i-1][j], lcsArr[i][j-1]);
      }
   }

   return lcsArr[m][n];
}

int main()
{
   // Top Down
   //lcs("ABCD", "ACED", 0);
   //lcs("ADCEB", "ACEB", 0);
   //cout << gLSS << endl;

   cout << lcs("ABCD", "ACEB") << endl;

   cout << lcsDP("ADCEB", "ACEB") << endl;
   cout << lcsDP("ADCEB", "") << endl;
   return 0;
}
