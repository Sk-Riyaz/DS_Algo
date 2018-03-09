#include<stdio.h>
#include<iostream>

using namespace std;

// Prob: https://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst/0

void printLeaf( const int arr[], const int start, const int end )
{
   if( start >= end )
   {
      if( start == end )
         cout << arr[start] << " ";
      return;
   }

   int j = start+1;
   while( j <= end && arr[start] >= arr[j] ) j++;

   printLeaf( arr, start+1, j-1 );
   printLeaf( arr, j, end );
}

int main()
{
   int T;
   cin >> T;
   while( T-- )
   {
      int n;
      cin >> n;
      int arr[n];
      for( int i = 0; i < n; ++i )
      {
         cin >> arr[i];
      }

      printLeaf( arr, 0, n-1 );
      cout << endl;
   }
   return 0;
}
