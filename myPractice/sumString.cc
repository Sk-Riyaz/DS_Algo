#include<stdio.h>
#include<iostream>

int leftSum(int left, int right)
{
   leftSum( left/10, (right*10) + left%10 ) + right;
}

int isSumEq(int arr[], int curI, int left, int right)
{
   if( !curI )
      return 0;

   if( right == left );

   isSumEq(arr, curI-1, left/10, (right*10)+arr[curI-1]);
}

int main()
{
   int arr[] = {1, 2, 2, 4, 3, 6};
   int n = sizeof(arr)/sizeof(arr[0]);
   isSumEq(arr, n, 122436, 0);
}
