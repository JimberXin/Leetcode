#include<iostream>
#include<stack>
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
	 TreeNode*left;
	 TreeNode* right;
	 TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    void flatten(TreeNode *root)
	{
		//
		TreeNode* head = root;
		   while(NULL != root)
		   {
			         if(NULL != root ->left)
					 {
						  TreeNode* pt = root -> left;
						   while( NULL != pt -> right)
							    pt =  pt -> right;
						   pt -> right =  root -> right;
						   root -> right = root -> left;
						   root -> left = NULL;
					 }
					 else
						 root = root -> right;
		   }
         //
		      while( NULL != head)
			  {
				    cout << head -> val << " " ;
					head =  head -> right;
			  }
		//
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
};


int main()
{
	Solution s;
	TreeNode* root =  s.createTree();
	  s.flatten(root);
	
	 
	cin.get();
	getchar();
	return 0;
}

