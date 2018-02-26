#include<stdio.h>
#include<iostream>
#include<string>

/* Prob:
   Find all anagrams of the word "abcd".
 */

void perm( const std::string &prob, const std::string sol )
{
   if( prob.empty( ) )
   {
      std::cout << sol << std::endl;
      return;
   }

   //for( int i = 0; i < prob.length( ); ++i )
   for( int i = prob.length( ) - 1; i >= 0; --i )
   {
      std::string newProb( prob );
      newProb.erase(i, 1);
      perm( newProb, sol + prob[i] );
   }
}

int main()
{
   perm( "abc", "" );
   return 0;
}
