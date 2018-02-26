#include<iostream>

using namespace std;

/* Prob:
   Sum of all leaf nodes that are to the left of its parent in a tree.
 */

struct Node
{
   int data;
   Node *left;
   Node *right;

   Node( int inp )
   {
      data = inp;
      left = NULL;
      right = NULL;
   }

   Node( int inp, Node *l, Node *r )
   {
      data = inp;
      left = l;
      right = r;
   }
};

int leftLeafSum( Node *root, bool isLeft )
{
   if( NULL == root )
   {
      return 0;
   }

   if( NULL == root->left && NULL == root->right )
   {
      return isLeft ? root->data : 0;
   }

   int leftSum = leftLeafSum( root->left, true );
   int rightSum = leftLeafSum( root->right, false );
   return leftSum + rightSum;
}

int main()
{
#if 0
   //Node *root = new Node( 6 );
   //root->left = new Node( 8 );
   //root->right = new Node( 4 );

   root->left->left = new Node( 1 );
   root->left->right = new Node( 9 );
   root->left->right->left = new Node( 10 );

   root->right->left = new Node( 5 );
   root->right->right = new Node( 3 );

   root->right->left->left = new Node( 2 );
   root->right->left->right = new Node( 8 );
#endif


   Node *root = new Node( 6,
         new Node(8,
            new Node(1),
            new Node(9,
               new Node(10),
               NULL)),
         new Node(4,
            new Node(5,
               new Node(2),
               new Node(8)),
            new Node(3)) );

   cout << leftLeafSum( root, false ) << endl;
   return 0;
}
