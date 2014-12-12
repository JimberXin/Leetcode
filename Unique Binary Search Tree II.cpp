#include<iostream>
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
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) 
  {
    vector<TreeNode *> result;
    result = buildBST(0,n-1);

    return result;
    }

  vector<TreeNode*>  buildBST(int begin,int end)
  {
    vector<TreeNode*> Tree ;
    //****************No elements***********************
    if(begin > end)
      {
	Tree.push_back (NULL);
	return Tree;
      }
    //************More than one elements******************
    else
      {
	for(int i=begin; i <=  end; i++)
	  {
	    vector<TreeNode*> left =  buildBST(begin,i-1);
	    vector<TreeNode*>  right =  buildBST(i+1,end);
	    for(int j = 0; j<left.size();j++)
	      {
		for(int k=0; k< right.size();k++)
		  {
		    TreeNode* root =  new TreeNode(i+1);
		    Tree.push_back (root);
		    root -> left = left[j]; //j elements in left
		    root -> right  = right[k]; // k elements in right
		  }
	      }				     
	  }	
	return Tree;
      }
  }
};

int main(void)
{
  Solution s;
  vector<TreeNode*> result = s.generateTrees(5);
  getchar();
  return 0;
}
