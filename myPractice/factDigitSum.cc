#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/fact-digit-sum/0

vector< long > getFacts()
{
   vector< long > fact(10, 1);
   for( int i = 1; i < 10; ++i )
   {
      fact[i] *= fact[i-1]*i;
   }
   return fact;
}

void getSmallFact(long int reqSum, const vector< long > &fact)
{
   vector< int > ans;
   while( reqSum )
   {
      for( int j = 9; j >= 0; --j )
      {
         if( reqSum >= fact[j] )
         {
            reqSum -= fact[j];
            ans.push_back(j);
            break;
         }
      }
   }
   sort( ans.begin(), ans.end() );
   for( int i = 0; i < ans.size(); ++i )
      cout << ans[i];
   cout << endl;
}

int main()
{
   int T;
   cin >> T;
   vector< long > fact = getFacts( );
   while(T--)
   {
      long int n;
      cin >> n;
      getSmallFact( n, fact );
   }
   return 0;
}
