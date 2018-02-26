#include<stdio.h>

bool binarySearch( const int a[], int low, int high, const int searchNum )
{
   while( low <= high )
   {
      //Based on Imtiaz Comments: Made changes
      int mid = low + ((high - low) / 2);
      if( searchNum == a[mid] )
      {
         return true;
      }

      //Based on Imtiaz Comments: Made changes
      //else if( searchNum < a[mid] )
      if( searchNum < a[mid] )
      {
         high = mid-1;
      }
      else if( searchNum > a[mid] )
      {
         low = mid+1;
      }
   }
   return false;
}

int main()
{
   int n;
   printf("Enter max numbers: ");
   scanf("%d", &n);
   int a[n];
   printf("Enter numbers in ascending order: ");
   for( int i = 0; i < n; ++i)
   {
      scanf("%d", &a[i]);
   }
   
   int searchNum = 0;
   printf("Enter number to search: ");
   scanf("%d", &searchNum);
   bool found = binarySearch( a, 0, n, searchNum );
   printf("%s\n", found ? "true" : "false");
   return 0;
}
