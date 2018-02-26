#include<stdio.h>
#include<map>
#include<vector>

using namespace std;

int main()
{
   int n;
   scanf("%d", &n);
   int arr[n];
   map< int, int > distinctEleCount;
   int prevEle = 0;
   int continuousCount = 0;
   for( int i = 0; i < n; ++i )
   {
      scanf("%d", &arr[i]);
      distinctEleCount[arr[i]] = 0;
   }

   unsigned int const totalDistinctEle = distinctEleCount.size();
   distinctEleCount.clear( );
   long long int sum = 0;
   int i = 0, j = 0;
   unsigned int totalElesCovered = 0;
   while( i < n )
   {
      if( distinctEleCount.size() == totalDistinctEle )
      {
         sum += 1 + (n-totalElesCovered);
         if( --distinctEleCount[arr[j]] <= 0 )
         {
            distinctEleCount.erase( arr[j] );
         }
         j++;
      }
      else
      {
         distinctEleCount[arr[i]]++;
         totalElesCovered++;
         ++i;
      }
   }

   if( distinctEleCount.size() == totalDistinctEle )
   {
      sum += 1 + (n-totalElesCovered);
   }
   printf("%lld\n", sum);
   return 0;
}
