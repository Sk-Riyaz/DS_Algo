#include<stdio.h>
#include<iostream>

using namespace std;

void nPerm(const int n, int n1, int n0, std::string ans)
{
   if( n1 < n0 )
      return;

   if( !n )
   {
      cout << ans << " ";
      return;
   }

   nPerm( n-1, n1+1, n0, ans+"1" );
   nPerm( n-1, n1, n0+1, ans+"0" );
}

int main()
{
   int T;
   cin >> T;
   while( T-- )
   {
      int n;
      cin >> n;
      nPerm(n, 0, 0, std::string());
      cout << endl;
   }
   return 0;
}
