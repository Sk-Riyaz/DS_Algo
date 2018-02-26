#include<iostream>
#include<string>

using namespace std;

/* Prob: 
   Print all permutations of n a b c
 */

int count = 0;
void permRep(int na, int nb, int nc, string s)
{
   if( !na && !nb && !nc )
   {
      count++;
      cout << s << endl;
      return;
   }

   if( na )
      permRep(na-1, nb, nc, s+"a");

   if( nb )
      permRep(na, nb-1, nc, s+"b");

   if( nc )
      permRep(na, nb, nc-1, s+"c");
}

int main()
{
   permRep(2, 2, 2, "");
   cout << count << endl;
   return 0;
}
