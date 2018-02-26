#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void reverseTP( const std::string &prob, int index, string sol )
{
   if( !index )
   {
      cout << sol << endl;
      return;
   }

   reverse( prob, index-1, sol+prob[index-1]);
}

std::string reverseBU( std::string prob )
{
   if( prob.empty() )
   {
      return "";
   }
   
   string tempSol = reverseBU( prob.substr(1) );
   return tempSol + prob[0];
}

int main()
{
   //#reverse( "abcd", 4, "" );
   cout << reverseBU( "abcd" ) << endl;
   return 0;
}
