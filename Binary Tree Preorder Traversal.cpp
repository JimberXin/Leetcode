//Last Modified: 2014/12/18
//Author: Junbo Xin

/*
**************************Problem Description**************************
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?


 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;


struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root){
    vector<int> values;
    stack<TreeNode*> BSstack;
    while(root != NULL || !BSstack.empty()){
      while(root != NULL){
	// cout << root -> val << " ";
	values.push_back(root->val);
	BSstack.push(root);
	root = root->left;
      }
      root = BSstack.top();
      BSstack.pop();
      root = root->right;
    }
    return values;
  }

public:
  TreeNode* createTree(void){    
    int data; 
    TreeNode* root;
    cin >> data;
    if(data == -1)
      root = NULL;
    else
      { 
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = data;
	root->left  = createTree();
	root->right = createTree();
      }
    return root;
  }
};

int main()
{
  Solution s;
  TreeNode* root =  s.createTree();
  vector<int> pre = s.preorderTraversal(root);
  for(vector<int>::iterator it = pre.begin(); it != pre.end(); ++it)
    cout << *it << " " ;
	 
  cin.get();
  getchar();
  return 0;
}
