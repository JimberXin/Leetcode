#include<iostream>
#include<stdio.h>
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
//int A[]= {1,2,3,-1,-1,4,-1,-1,5};
struct TreeNode
{
	   int val;
	   TreeNode *left;
	   TreeNode *right;
	   TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    bool isValidBST(TreeNode *root)
	{
        //
		       return  isValidMaxMin(root, INT_MIN,INT_MAX);
		//
    }

public:
	bool isValidMaxMin(TreeNode* root, int min ,int max)
	{
		         if(NULL == root)
					   return true;
				 else if(root ->val > min &&  root ->val < max)
					  return ( isValidMaxMin(root ->left, min,root -> val) && isValidMaxMin(root ->right, root->val, max));
				 else 
					   return false;
	}
public:
	TreeNode* createTree(void)
	{    
		  int data; 
		  TreeNode* root;
		  cin >> data;
		   if( data == -1)
			    root = NULL;
		   else
		   { 
			     root = (TreeNode*)malloc(sizeof(TreeNode));
			     root -> val = data;
				 root -> left  = createTree();
				 root -> right = createTree();
		   }
		   return root;
	}

public:
	void PreOrderTree(TreeNode *T)
	{
		    if(NULL != T)
			{
				   PreOrderTree(T -> left);
				   cout <<  T -> val << " ";
				   PreOrderTree(T -> right);
			}
	}

 public:
	void   InOrderTree(TreeNode *T)
	{
		    if(NULL != T)
			{
				   cout <<  T -> val << " ";
				   InOrderTree(T -> left);
				   InOrderTree(T -> right);
			}
	}

	 public:
	void   PostOrderTree(TreeNode *T)
	{
		    if(NULL != T)
			{
				 
				   PostOrderTree(T -> left);
				   PostOrderTree(T -> right);
				     cout <<  T -> val << " ";
			}
	}
};

int main()
{
	   // { 1,2,#,#,3,#,#,4,#,5,#,#,#}
	   Solution s;
	  TreeNode* root = s.createTree();
	  //cout << " PreOrder of the BST is : ";
	  //s.PreOrderTree(root);
	  //cout << endl << "InOrder of the BST is: ";
	  //s.InOrderTree(root);
	  //cout <<  endl << "PostOrder of the BST is:";
	  //s.PostOrderTree(root);
	  //cout << endl << root -> right -> left -> right  -> val <<  endl; //outht to be 5
	  //cout <<  root -> left -> val  << endl;

	   cout  << " whether it is a valid BST:  " <<  s.isValidBST(root) << endl;

	   cin.get();
	    getchar();
		return 0;
}