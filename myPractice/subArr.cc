#include<stdio.h>
//#include<iostream>
//#include<algorithm>

//using namespace std;

int max( int a, int b )
{
   return a > b ? a : b;
}

long long int scanint();

inline long long int scanint( )
{
   int x;
   register int c = getchar_unlocked();
   x = 0;
   int neg = 0;
   for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
   if(c=='-') {neg=1;c=getchar_unlocked();}
   for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
   if(neg) x=-x;
   return x;
}


int main()
{
   int t = scanint( );
   while( t-- )
   {
      int n = scanint( ), c = scanint( );
      int val = scanint( );
      int gMax = c - val, lMax = c - val;
      for( int i = 1; i < n; ++i )
      {
         val = c - scanint( );
         lMax = max( val, lMax + val );
         gMax = max( lMax, gMax );
      }

      if( gMax < 0 ) gMax = 0;
      printf( "%d\n", gMax );
   }
   return 0;
}
