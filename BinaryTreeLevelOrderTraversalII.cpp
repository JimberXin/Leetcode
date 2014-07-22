#include<iostream>
#include<queue>
#include<vector>

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
		TreeNode(int x): val(x),left(NULL), right(NULL){}
};
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) 
    {
        //
            queue<TreeNode*> q;
			vector< vector<int> >  values;
			vector<int> pair;
			// curNum is the current levels' total nodes number; nextNum is the next level's total nodes number
            int curNum = 1;
			int nextNum = 0;
			if(NULL ==  root)
				return values ; // return [];
			q.push(root);
			pair.push_back(root->val);
			values.push_back(pair);
			pair.clear();
			while( !q.empty())
			{
				   root = q.front();
				   q.pop();
				   curNum --;
				   
			   if( NULL != root -> left)
			   {
				    q.push(root->left);
					pair.push_back(root -> left ->val);
					nextNum ++;
			   }
			   if(NULL != root -> right)
			   {
				     q.push(root -> right);
					 pair.push_back(root -> right -> val);	
					 nextNum ++;
			   }
           		  
			     if( 0 == curNum)
				 {
					   if( !pair.empty() )
					      values.push_back(pair);
						pair.clear();
					    curNum = nextNum;
						nextNum = 0;
				 }
			}
		
		     reverse(values.begin(),values.end());
						 
            return values;
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

int main()
{
	/*vector<vector < int> > outside;
	vector<int> inside;
	vector< vector<int> > ::iterator it;
      it =  outside.begin();
	  inside.push_back(1);
	  inside.push_back(2);
	  inside.push_back(3);
	  outside.push_back(inside);
	   inside.clear();
	   inside.push_back(4);
	   inside.push_back(5);
	  outside.push_back( inside);*/
	 Solution s;
	 TreeNode* root = s.createTree();
	 vector< vector<int> > output =  s.levelOrderBottom(root);
	  cin.get();
	  getchar();
	  return 0;
}