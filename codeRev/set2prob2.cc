#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

/* Prob:
   Print all well-formed combinations of N {}
   N = 1 --> {}
   N = 2 --> {}{}, {{}}
   N = 3 --> {}{}{}, {}{{}}, {{}}{}, {{}{}}, {{{}}}
 */

void pb( int no, int nc, string s )
{
   if( !no && !nc )
   {
      cout << s << std::endl;
      return;
   }

   if( no )
      pb( no-1, nc, s+"{" );

   if( nc>no )
      pb( no, nc-1, s+"}" );
}

int main()
{
   pb(3, 2, "");
   return 0;
}
