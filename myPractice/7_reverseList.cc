#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct Node
{
   int data;
   struct Node *next;
   
   Node(int inp)
   {
      data = inp;
      next = NULL;
   }
};

#if 0
void reverseLL( const Node *parent )
{
   if( NULL == parent )
   {
      return;
   }

   reverseLL( parent, parent->next );
   cout << parent->data << endl;
}
#endif

void printLL( Node *ptr )
{
   while ( ptr != NULL )
   {
      cout << ptr->data << endl;
      ptr = ptr->next;
   }
}

void reverseLL( Node *p, Node *sol )
{
   if( NULL == p )
   {
      printLL( sol );
      return;
   }

   Node *np = p->next;
   p->next = sol;
   reverseLL( np, p );
}

int main()
{
   Node *head = new Node(0);

   Node *temp = head;
   for( int i = 1; i < 10; ++i )
   {
      temp->next = new Node(i);
      temp = temp->next;
   }

   reverseLL( head, NULL );
   return 0;
}
