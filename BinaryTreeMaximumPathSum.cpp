#include <iostream>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{   
	    int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int maxPathSum(TreeNode *root)
    {
        //
          if(NULL ==  root)
			   return  0;
		  else if(NULL == root -> left && NULL == root -> right)
			  return root ->val;
		  else    if(NULL == root -> left && NULL != root ->right)
					return root -> val + max(0,maxRootLeaf(root -> right) );
		   else  if(NULL == root -> right && NULL != root -> left)
					return root -> val +  max(0,maxRootLeaf(root -> left) );
			else
			{
				     return  ( root -> val +maxRootLeaf(root -> left) + maxRootLeaf(root -> right)   );
		    }
		  }
        //

public:
	int maxRootLeaf(TreeNode *tree)
	{
		    if(NULL == tree)
				 return 0;
			else 
			{
				if( NULL ==  tree -> left && NULL ==  tree -> right)
					 return tree -> val;
				else if( NULL != tree -> left && NULL == tree ->right)
					  return (tree -> val + maxRootLeaf(tree -> left) );
				else if( NULL != tree -> right && NULL ==  tree ->left)
					 return ( tree -> val  + maxRootLeaf( tree -> right) );
				else 
				    return (tree -> val +max( maxRootLeaf(tree -> left), maxRootLeaf(tree -> right)) );
			}
	}
	public:
	TreeNode* createTree()
	{
		   int data;
		   TreeNode* root;
		   cin >> data;
		   if(data ==  -1)
			    root = NULL;
		   else
		   {
		    root = (TreeNode*) malloc(sizeof(TreeNode));
			root -> val =  data;
			root -> left =  createTree();
			root -> right = createTree();
		   }
			return root;
	}
};


int main()
{
	  Solution s;
	  TreeNode * root = s.createTree();
	  int maxSum =  s.maxPathSum(root);
	  cout << "Maximum of the path sum is : " << maxSum << endl;
	  cin.get();
	  getchar();
	  return 0;
}