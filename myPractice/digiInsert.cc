#include<stdio.h>
#define NONE 10001

long long int scanint();

inline long long int scanint( )
{
   int x;
   register int c = getchar_unlocked();
   x = 0;
   int neg = 0;
   for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
   if(c=='-') {neg=1;c=getchar_unlocked();}
   for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
   if(neg) x=-x;
   return x;
}

int main()
{
   int T = scanint();
   while( T-- )
   {
      int n = scanint();
      int arr[n];
      for( int i = 0; i < n; ++i )
      {
         arr[i] = scanint();
      }

      int valToInsert = arr[n/2];
      int firstNeg = NONE;
      int secPos = NONE;
      if(n % 2 == 0)
         valToInsert += arr[n/2-1];

      for( int i = 0; i < n; ++i )
      {
         int ele = arr[i];
         if(ele == 0)
         {
            printf("%d ", ele);
            if(secPos == NONE)
            {
               secPos = -1;
            }
            else if(secPos == -1)
            {
               secPos = ele;
               continue;
            }
            printf("%d ", valToInsert);
         }
         else if(ele < 0)
         {
            if(firstNeg == NONE)
            {
               firstNeg = ele;
               continue;
            }
            printf("%d ", ele);
         }
         else if(ele > 0)
         {
            if(secPos == NONE)
            {
               secPos = -1;
            }
            else if(secPos == -1)
            {
               secPos = ele;
               continue;
            }
            printf("%d ", ele);
         }
      }
      printf("\n");
   }
   return 0;
}
