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
{ int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) 
    {
        //
            stack<int> BSsum;
			stack<TreeNode*> BSroot;
			int add = 0;
			if(NULL ==  root)
				  return false;
			while( NULL != root || !BSsum.empty())
			{
				   while(NULL!=root)
				   {
					      add +=  root -> val;
						  BSroot.push(root);
					      BSsum.push(add);
					      root =  root ->left;
				   }
				       root =  BSroot.top();
					   add= BSsum.top();
					   if(add == sum && root ->right == NULL && root == NULL )
					   {
						  /* cout << " It has the nodes that adds to the sum: " << endl;
						   while(!BSroot.empty())
						   {
						      cout << BSroot.top()  -> val << " + " ;
						      BSroot.pop();
						   }
						   cout << endl;*/
						    return true;
					   }
					   else
						     BSsum.pop();
					    BSroot.pop();
						root =  root ->right;
			}
		//	cout<< "Dont have" << endl;
			return false;
        
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
	   
	bool is = s.hasPathSum(root,1);
	cout << "Whether has sum or not: " <<  is <<  endl;
	 
	cin.get();
	getchar();
	return 0;
}
