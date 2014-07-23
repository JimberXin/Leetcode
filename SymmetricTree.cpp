#include<iostream>
using namespace std;

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
	  TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root)
	{
        //
		   if( NULL ==  root )
			   return true;
		   else
			   return(isSameLeftRight(root -> left, root->right));
			  
		//
    }

public:
	bool isSameLeftRight(TreeNode* tree1, TreeNode* tree2)
	{
		     if(NULL == tree1 && NULL ==  tree2)
				 return true;
			 else if( (NULL ==  tree1 && NULL != tree2) || (NULL ==  tree2 && NULL != tree1) )
				 return false;
			 else if(tree1 -> val == tree2 -> val)
				  return (isSameLeftRight(tree1 -> left, tree2->right) && isSameLeftRight(tree1->right,tree2->left));
			         else
				  return false;
	}
public:
   TreeNode* createTree()
   {
		    TreeNode *root;
			int data;
		   cin  >> data;
		   if( data == -1)
			     root = NULL;
		   else 
		   {
			     root = (TreeNode*) malloc(sizeof(TreeNode));
				 root -> val = data;
				 root  -> left=  createTree();
				 root  -> right = createTree();
	       }
		   return root;
   }

};

int main()
{
	  Solution s;
	  cout << " Please create the tree: " << endl;
	  TreeNode * root =  s.createTree();
	  cout << "Whether it is a symmetric tree: " <<  s.isSymmetric(root) << endl;
	  cin.get();
	  getchar();
	  return 0;
}