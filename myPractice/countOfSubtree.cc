/*
   Please note that it's Function problem i.e.
   you need to write your solution in the form of Function(s) only.
   Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
   Structure of the node of the binary tree is as
   struct Node {
   int data;
   struct Node *left, *right;
   };
 */
// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X

// Prob: https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1

int getSumOfTree( Node *root, const int &x, int &count )
{
   if( !root ) return 0;

   int lSum = getSumOfTree( root->left, x, count );
   int rSum = getSumOfTree( root->right, x, count );

   if( lSum + rSum + root->data == x) count++;

   return (lSum + rSum + root->data);
}

int countSubtreesWithSumX(Node* root, int x)
{
   if (!root)return 0;

   int retVal = 0;
   getSumOfTree( root, x, retVal );
   return retVal;
}
