#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int gEnergy = -1;

void subseq(int arr[], int k, int curI, vector< int >sol, int energy)
{
   if( sol.size() >= k )
   {
      gEnergy = max( energy, gEnergy );
      return;
   }

   if( curI < 0 )
   {
      return;
   }
   
   vector< int > te = sol;
   int tEnergy = 0;
   if( te.empty() || te.back() > arr[curI] )
   {
      if( !te.empty() )
      {
         tEnergy = te.back() - arr[curI];
      }
      te.push_back( arr[curI] );
   }
   subseq(arr, k, curI-1, te, energy+tEnergy);
   subseq(arr, k, curI-1, sol, energy);
}

int main()
{
   int n, k;
   cin >> n >> k;
   //unsigned int arr[n];
   int arr[n];
   for( int i = 0; i < n; ++i )
   {
      cin >> arr[i];
   }

   subseq(arr, k, n-1, vector<int>(), 0);
   cout << gEnergy << endl;
}
