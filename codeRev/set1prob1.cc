#include<iostream>
#include<stdio.h>
#include<string>

/* Prob:
   Find all subsets of the word "abcd".
 */

void comb( std::string prob, std::string sol )
{
   if( prob.empty( ) )
   {
      std::cout << sol << std::endl;
      return;
   }

   comb( prob.substr(1), sol + prob[0] );
   comb( prob.substr(1), sol );
}

int main()
{
   comb("abc", "");
   return 0;
}
