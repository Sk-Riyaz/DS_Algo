#include<bits/stdc++.h>

using namespace std;

struct Node
{
   int data;
   struct Node *next;

   Node(int d, Node *n)
   {
      data = d;
      next = n;
   }

   Node(int d)
   {
      data = d;
      next = NULL;
   }
};

void printLL(Node *head)
{
   while( head != NULL )
   {
      cout << head->data << "->";
      head = head->next;
   }
}

Node *append(Node *head, int data)
{
   if( head == NULL ) return new Node( data );

   Node *itr = head;
   while( itr->next != NULL ) itr = itr->next;
   itr->next = new Node( data );
   return head;
}

Node *getMiddle( Node *head )
{
   if( NULL == head || NULL == head->next ) return head;
   Node *slow = head;
   Node *fast = head->next;

   while( slow && fast && fast->next )
   {
      slow = slow->next;
      fast = fast->next->next;
   }
   return slow;
}

Node *merge( Node *h1, Node *h2 )
{
   if( h1 == NULL ) return h2;
   if( h2 == NULL ) return h1;

   Node *start = NULL;
   Node *h = NULL;
   while( h1 && h2 )
   {
      if( h1->data < h2->data )
      {
         if( NULL == start )
         {
            start = h1;
            h = h1;
         }
         else
         {
            h->next = h1;
            h = h->next;
         }
         h1 = h1->next;
      }
      else
      {
         if( NULL == start )
         {
            start = h2;
            h = h2;
         }
         else
         {
            h->next = h2;
            h = h->next;
         }
         h2 = h2->next;
      }
   }

   while( h1 )
   {
      h->next = h1;
      h = h->next;
      h1 = h1->next;
   }

   while( h2 )
   {
      h->next = h2;
      h = h->next;
      h2 = h2->next;
   }
   return start;
}

Node *mergesort( Node *head )
{
   if( NULL == head || NULL == head->next ) return head;
   Node *mid = getMiddle( head );
   if( mid )
   {
      Node *next = mid->next;
      mid->next = NULL;
      mid = next;
   }

   Node *h1 = mergesort( head );
   Node *h2 = mergesort( mid );
   return merge( h1, h2 );
}

Node *revByKNodes(Node *head, int k)
{
   if( NULL == head ) return head;

   Node *cur = head;
   Node *pkl = NULL;
   while( cur != NULL )
   {
      Node *strt = cur;
      int i = 0;
      Node *prev = NULL;
      while( NULL != cur && i < k )
      {
         Node *next = cur->next;
         cur->next = prev;
         prev = cur;
         cur = next;
         i++;
      }

      if( NULL == pkl )
      {
         pkl = strt;
         head = prev;
      }
      else
      {
         pkl->next = prev;
         pkl = strt;
      }
   }
   return head;
}

Node *revByKNodesRecur(Node *head, int k)
{
   if( NULL == head || 1 >= k ) return head;

   Node *cur = head;
   Node *prev = NULL;
   Node *const start = cur;
   int i = 0;
   while( NULL != cur && i < k )
   {
      Node *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      i++;
   }

   start->next = revByKNodesRecur(cur, k);
   return prev;
}

Node *sortByKNodes( Node *head, int k )
{
   if( NULL == head || 1 >= k ) return head; 
   int cnt = 0;
   Node *next = head;
   Node *prev = NULL;
   while( cnt < k && next )
   {
      prev = next;
      next = next->next;
      cnt++;
   }
   prev->next = NULL;

   head = mergesort( head );
   prev = head;
   while( prev && prev->next ) prev = prev->next;
   prev->next = sortByKNodes( next, k );
   return head;
}

int main()
{
   //Node *head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6, new Node(7, new Node(8, new Node(9, new Node(10, new Node(11, NULL)))))))))));
   srand(time(NULL));
#if 0
   Node *head = NULL;
   for( int i = 1; i <= 11; ++i ) head = append( head, i );

   cout << "Before: ";
   printLL( head );
   cout << endl;
   head = revByKNodes( head, 4 );

   cout << "Intermediate: ";
   printLL( head );
   cout << endl;

   head = revByKNodes( head, 4 );

   cout << "After: ";
   printLL( head );
   cout << endl;
#endif

   Node *s = NULL;
   for( int i = 11; i >= 11; --i ) s = append( s, random()%100 );

   cout << "Before: ";
   printLL( s );
   cout << endl;

   //s = mergesort( s );

   //cout << "After: ";
   //printLL( s );
   //cout << endl;

   s = sortByKNodes( s, 5 );

   cout << "After: ";
   printLL( s );
   cout << endl;
   return 0;
}
