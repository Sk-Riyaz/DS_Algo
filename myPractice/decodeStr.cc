#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/decode-the-string/0

string getSubStr(string str)
{
   string retStr;
   if( str.empty() ) return retStr;

   vector< char > stack;
   int cnt = 1;
   stack.push_back(str[0]);
   for( int i = 1; !stack.empty( ) && i < str.length(); ++i )
   {
      if( str[i] == ']' && cnt == 1 )
      {
         for( int j = 1; j < stack.size(); ++j )
         {
            retStr.append( 1, stack[j] );
         }
         break;
      }
      else
      {
         stack.push_back(str[i]);
         if( str[i] == '[' )
            cnt++;
         else if( str[i] == ']' )
            cnt--;
      }
   }
   return retStr;
}

std::string getBaseString(const std::string str)                
{                                                               
   if( str.empty() )                                            
      return str;                                               

   string curStr;
   string digStr;
   long rep = 0;
   for( int i = 0; i < str.length(); ++i )
   {
      if( str[i] == '[' )
      {
         if( !digStr.empty() )
            rep = atol(digStr.c_str());
         string substr = getSubStr(str.substr(i));
         string reptStr = getBaseString(substr);
         while( rep-- )
            curStr.append(reptStr);
         i += substr.length()+1;
         digStr.clear();
      }
      else if(str[i] >= 48 && str[i] <= 57)
      {
         digStr.append(1, str[i]);
      }
      else if( !(str[i] >= 48 && str[i] <= 57) )
      {
         curStr.append(1, str[i]);
      }
   }
   return curStr;
}                                                               

int main()
{
   int T;
   cin >> T;
   while(T--)
   {
      string str;
      cin >> str;
      string repStr = getBaseString( str );
      cout << repStr << endl;
   }
   return 0;
}
