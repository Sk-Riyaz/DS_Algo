#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

/* Prob:
   Given a set of integers S, find any subset which adds to given target T.

   Example:
      S = {1, -10, 9, 4, 3, 2, 50, 12, 13, -5}
      T = 20
 */

bool compare( const std::vector< int > &a, const std::vector< int > &b )
{
   return a.size() < b.size();
}

void printSubsetWithSum( std::vector< int > &arr, const int target,
      std::vector< int > &subset, int subsetSum )
{
   if( target == subsetSum )
   {
      for( int i = 0; i < subset.size( ); ++i )
      {
         std::cout << subset[i] << " ";
      }
      std::cout << std::endl;
      exit(EXIT_SUCCESS);
   }

   if( arr.empty( ) )
      return;

   const int valueToadd = arr.back();
   arr.pop_back();

   //Added sum to the subset
   subset.push_back( valueToadd );
   printSubsetWithSum( arr, target, subset, subsetSum+valueToadd );

   //Not added sum to the subset
   subset.pop_back( );
   printSubsetWithSum( arr, target, subset, subsetSum );
}

int main()
{
   std::vector< int > arr= {1, -10, 9, 4, 3, 2, 50, 12, 13, -5};
   int target = 20;
#if 0
   //std::vector< int > arr;
   arr.clear();
   arr.push_back(2);
   arr.push_back(4);
   arr.push_back(6);
   //arr.push_back(7);
   //arr.push_back(13);
   //arr.push_back(9);
   target = 6;
#endif
   std::vector< int > subset;
   printSubsetWithSum( arr, target, subset, 0 );
#if 0
   std::vector< std::vector< int > > subsetsArr;
   printSubsetWithSum( arr, target, std::vector< int > (), 0, subsetsArr );

   //std::sort( subsetsArr.begin(), subsetsArr.end( ), compare );
   for( int i = 0; i < subsetsArr.size( ); ++i )
   {
      for( int j = 0; j < subsetsArr[i].size( ); ++j )
      {
         std::cout << subsetsArr[i][j] << " ";
      }
      std::cout << std::endl;
   }
#endif
   return 0;
}
