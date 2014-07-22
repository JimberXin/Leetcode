#include<iostream>
#include<vector>
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
	  TreeNode *left;
	  TreeNode *right;
	  TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root)
	{
        //
		     vector<int> values;
			 stack<TreeNode*> BSstack;
			 while(NULL!=root || !BSstack.empty())
			 {
				 ///  Traversing the left nodes of root
				    while(NULL != root)
					{
						   BSstack.push(root);
						   root =  root -> left;
					}
					
					if( !BSstack.empty())
					{
					    root =  BSstack.top();
						values.push_back(root -> val);
						BSstack.pop();
						root =  root -> right;
					}
			 }
			 return values;

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

int main(void)
{
	 Solution s;
	 TreeNode* root = s.createTree();
	 vector<int> in = s.inorderTraversal(root);
	  for(vector<int>::iterator it =  in.begin(); it != in.end(); it++)
		  cout << *it << " " ;
	  cout << endl;
	 cin.get();
	 getchar();
	 return 0;
}
