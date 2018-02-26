#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector< long int > sdSeries(int n)
{
   vector< long int > out;
   out.push_back(0);
   out.push_back(1);
   for( int i = 2; i < n; ++i )
   {
      out.push_back(pow(out[i-2], 2) - out[i-1]);
   }
   return out;
}

int main()
{
   int T, n;
   cin >> T;
   while(T--)
   {
      cin >> n;
      vector< long int > out = sdSeries(n);
      for( int i = 0; i < out.size() && i < n; ++i )
      {
         cout << out[i] << " ";
      }
      cout << endl;
   }
   return 0;
}
