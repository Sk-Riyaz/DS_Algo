#include<stdio.h>
#include<iostream>
#include<vector>

/* Prob:
   Given a set of integers, find if it is possible to divide it into
   two groups such that sum of one group is a multiple of 5 and
   sum of the other is odd.
 */

const int multipleVal = 3;
void Multiple5OddSum( 
      const std::vector<int> &prob, int index,
      const std::vector<int> &s1,
      const std::vector<int> &s2,
      int s1Sum, int s2Sum )
{
   if( index >= (int)prob.size( ) )
   {
      return;
   }

   // Discuss with interviewer if empty set to be considered
   if( index < 0 )
   {
      if( ( s1Sum % multipleVal == 0 && s2Sum % 2 == 1 ) ||
            ( s1Sum % 2 == 1 && s2Sum % multipleVal == 0 ) )
      {
         std::cout << "S1: ";
         for( auto val : s1 )
         {
            std::cout << val << " ";
         }
         std::cout << std::endl;

         std::cout << "S2: ";
         for( auto val : s2 )
         {
            std::cout << val << " ";
         }
         std::cout << std::endl;
      }
      return;
   }

   int v = prob[index];
   --index;

   std::vector< int > tS1( s1 );
   std::vector< int > tS2( s2 );

   tS1.push_back( v );
   Multiple5OddSum( prob, index, tS1, tS2, s1Sum+v, s2Sum );

   tS1.pop_back( );
   tS2.push_back( v );
   Multiple5OddSum( prob, index, tS1, tS2, s1Sum, s2Sum+v );
#if 0
   int v = prob.back();
   prob.pop_back();

   std::vector< int > tS1( s1 );
   std::vector< int > tS2( s2 );

   tS1.push_back( v );
   Multiple5OddSum( prob, tS1, tS2, s1Sum+v, s2Sum );

   tS1.pop_back( );
   tS2.push_back( v );
   Multiple5OddSum( prob, tS1, tS2, s1Sum, s2Sum+v );
#endif
}

int main( )
{
   std::vector<int> arr = {1, 0, 6};
   std::vector<int> s1, s2;
   Multiple5OddSum( arr, arr.size()-1, s1, s2, 0, 0 );
   return 0;
}
