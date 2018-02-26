#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/next-happy-number/0

int getSumOfSquares(int num)
{
   int retVal = 0;
   while(num)
   {
      int val = num%10;
      retVal += val*val;
      num /= 10;
   }
   return retVal;
}

bool isHappNum(int n)
{
   bool isHappyNum = false;
   vector< int > seqNum;
   vector< int >::iterator it;
   int prevN = n;
   do
   {
      n = getSumOfSquares(n);
      if( n == 1 )
      {
         isHappyNum = true;
         break;
      }

      seqNum.push_back(prevN);
      prevN = n;
      it = std::find( seqNum.begin(), seqNum.end(), n );
   }while( it == seqNum.end() );
   return isHappyNum;
}

int main()
{
   int T;
   cin >> T;
   vector< bool >happyNum(1001, false);
   for( int i = 1; i < 1001; i++ )
   {
      if( isHappNum(i) )
         happyNum[i] = true;
   }

   while(T--)
   {
      int n;
      cin >> n;
      for( int i = n+1; i < 1001; ++i )
      {
         if( happyNum[i] )
         {
            cout << i << endl;
            break;
         }
      }
   }
   return 0;
}
