//Last Modified: 2014/12/17
//Author:  Junbo Xin

/*
//************************Problem Description*************************
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, 
where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".


 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
*/


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root){
    vector<int> values;
    stack<TreeNode*> BSstack;
    while(root != NULL || !BSstack.empty()){
      //  Traversing the left nodes of root
      while(root != NULL){
	BSstack.push(root);
	root = root->left;
      }					
      if(!BSstack.empty()){
	root = BSstack.top();
	values.push_back(root->val);
	BSstack.pop();
	root = root->right;
      }
    }
    return values;
  }


public:
  TreeNode* createTree(void){    
    int data; 
    TreeNode* root;
    cin >> data;
    if( data == -1)
      root = NULL;
    else
      { 
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = data;
	root->left = createTree();
	root->right = createTree();
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
