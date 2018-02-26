#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct Pair
{
   int T;
   long long int S;

   Pair( int t, long long int s )
   {
      T = t;
      S = s;
   }
};

#if 0
void maxHires( const vector< Pair > &prob,
      vector< Pair > sol, int hireCount )
{
   if( prob.empty() )
   {
      MAX_HIRE_CNT = MAX_HIRE_CNT > hireCount ? MAX_HIRE_CNT : hireCount;
      return;
   }

   std::vector< Pair >temp(prob);
   const Pair toHire = temp.back();

   bool hire = true;
   if( !sol.empty( ) )
   {
      if( !(( toHire.T > sol.back().T &&
                  toHire.S > sol.back().S )||
               ( toHire.T <= sol.back().T &&
                 toHire.S <= sol.back().S )) )
      {
         hire = false;
      }
   }

   temp.pop_back( );
   if( hire )
   {
      sol.push_back( toHire );
      maxHires( temp, sol, hireCount+1 );
      sol.pop_back( );
      maxHires( temp, sol, hireCount );
   }
   else
   {
      maxHires( temp, sol, hireCount );
   }
}
#endif

int maxHires(vector< Pair > inp)
{
   if( !inp.size() )
   {
      return 0;
   }

   int globalHireCnt = 1;
   vector< int > hireCntSoFar(inp.size(), 1);
   for( int i = 1; i < inp.size(); ++i )
   {
      int localHireCnt = 0;
      for( int j = 0; j < i; ++j )
      {
         if( inp[i].T <= inp[j].T &&
               inp[i].S <= inp[j].S )
         {
            localHireCnt = max(localHireCnt, hireCntSoFar[j]);
         }
      }

      hireCntSoFar[i] += localHireCnt;
      globalHireCnt = max( globalHireCnt, hireCntSoFar[i] );
   }
   return globalHireCnt;
}

bool compare(const Pair &a, const Pair &b)
{
   return a.S > b.S;
}

int main()
{
   int n;
   cin >> n;
   std::vector< Pair > inp;
   for( int i = 0; i < n; ++i )
   {
      int T, S;
      cin >> T >> S;
      inp.push_back(Pair(T, S));
   }

   sort(inp.begin(), inp.end(), compare);
   std::vector< Pair > sol;
   //cout << maxHires(inp, sol, 0) << endl;
   cout << maxHires(inp) << endl;
}
