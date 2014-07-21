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
	  TreeNode* right;
	  TreeNode(int x):val(x), left(NULL),  right(NULL){}
};

//My solution uses the postorder traversal of the tree, uses last to mark the last nodes that I visit, and use two stacks:
//nodeStack to save the nodes, sumStack to save the current passing nodes' sum.
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        //
                 stack<TreeNode*> nodeStack;
				 stack<int> sumStack;
				 int add = 0;
				 TreeNode* last =  NULL;
				 vector< vector<int> > all;
				 vector<int> nodes;

				 while( NULL != root || !nodeStack.empty( ) )
				 {
					    while(NULL != root)
						{
							   nodeStack.push(root);
							   add += root -> val;
							   sumStack.push(add);
							   root = root -> left;
						}
						  root = nodeStack.top();
						  add = sumStack.top();
				 
				 if(NULL == root -> right || last == root-> right)
				 {
					   last = root;
					   //deal with the case that the root-leaf path equals sum
					   if(NULL == root -> left && NULL == root -> right && sum == add)
					   {
						   	      stack<TreeNode*> temp;
						    while(!nodeStack.empty())
						     {		
							    TreeNode* nodetemp = nodeStack.top();
							    temp.push(nodetemp);
							    nodeStack.pop();
						     }
						    while(!temp.empty())
							  {
								   TreeNode* nodetemp = temp.top();
								   nodes.push_back(nodetemp->val);
								   nodeStack.push(nodetemp);
								   temp.pop();
							   }
							all.push_back(nodes);
							nodes.clear();
					   }
					   //visit this node root
					   nodeStack.pop();
					   sumStack.pop();
					   root = NULL;				   
				 }
				 else
					 root =  root ->right;

				 }
				// all.push_back(nodes);
				 return all;

           
        //
        
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

int main(void)
{  
	   Solution s;
	   TreeNode* root = s.createTree();
	   vector< vector<int> > v = s.pathSum(root,22);
	   vector<vector < int> >::iterator outside;
	    vector<int>::iterator inside ;
		for(outside = v.begin(); outside != v.end(); outside++)
		{
			  for(inside = outside -> begin();inside != outside ->end(); inside++)
				    cout << *inside << " ";
		    cout << endl;
		}
		cin.get();
	   getchar();
	   return 0;
}

