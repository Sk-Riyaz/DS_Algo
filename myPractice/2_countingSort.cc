#include<stdio.h>

// Question: How to do inline meaning
// on the array itself without creating countArr
void countSort(int arr[], int n)
{
   // Find the max number from the array
   int maxNum = -1;
   for( int i = 0; i < n; ++i )
   {
      if( maxNum < arr[i] )
      {
         maxNum = arr[i];
      }
   }

   // Initialize the count array
   int countArr[maxNum+1];
   for( int i = 0; i < maxNum; ++i )
   {
      countArr[i] = 0;
   }

   // Count the elements of the array
   for( int i = 0; i < n; ++i )
   {
      countArr[arr[i]]++;
   }

   // Restore the elements to the original array
   int prevArrPos = 0;
   for( int i = 0; i <= maxNum; ++i )
   {
      for( int j = 0; j < countArr[i]; ++j )
      {
         arr[prevArrPos] = i;
         prevArrPos++;
      }
   }
}

int main()
{
   int n;
   printf("Enter max numbers: ");
   scanf("%d", &n);
   int a[n];
   printf("Enter numbers: ");
   for( int i = 0; i < n; ++i)
   {
      scanf("%d", &a[i]);
   }
   countSort(a, n);

   for( int i = 0; i < n; ++i)
   {
      printf("%d ", a[i]);
   }
   printf("\n");
   return 0;
}
