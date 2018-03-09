#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void strrev( char *start, char *end )
{
   while( start < end )
   {
      char temp = *start;
      *start = *end;
      *end = temp;

      ++start;
      --end;
   }
}

void revByWord( char *str )
{
   char *wordBegin = NULL;
   char *temp = str;

   while( NULL != temp && *temp )
   {
      if( wordBegin == NULL && *temp != ' ' )
      {
         wordBegin = temp;
      }
      if( (NULL != wordBegin) && (*(temp+1) == ' ' || *(temp+1) == '\0') )
      {
         strrev( wordBegin, temp );
         wordBegin = NULL;
      }
      ++temp;
   }
}

void revByWordR( char *str )
{
   char *start = str;
   char *end = str;
   while( NULL != end && *end != '\0' ) ++end;
   while( NULL != start && start < end )
   {
      while( NULL != start && start < end && *start == ' ' ) ++start;
      char *wEnd = start+1;
      while( NULL != wEnd && wEnd < end && *wEnd != ' ' ) ++wEnd;
      strrev( start, --wEnd );
      start = wEnd;
      ++start;
   }

   if( NULL != str )
      strrev( str, end-1 );
}

int main()
{
   char arr[] = "  I   am    working";
   //revByWord( arr );
   revByWord( arr );
   //revByWord( arr );
   cout << "[" << arr << "]" << endl;
   return 0;
}
