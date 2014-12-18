//Last Modified: 2014/12/18
//Author: Junbo Xin

/*
*******************Problem Description**************************
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

*/

#include <iostream>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))


struct TreeNode{   
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
  int maxPathSum(TreeNode *root){
    if(root == NULL)
      return  0;
    else if(root->left == NULL && root->right == NULL)
      return root ->val;
    else if(root->left == NULL && root->right != NULL)
      return root->val + max(0,maxRootLeaf(root->right));
    else if(root->right == NULL && root->left != NULL)
      return root->val +  max(0,maxRootLeaf(root->left));
    else
      return (root->val +maxRootLeaf(root->left) + maxRootLeaf(root->right));
  }

public:
  int maxRootLeaf(TreeNode *tree){
    if(tree == NULL)
      return 0;
    else {
      if(tree->left == NULL && tree->right == NULL)
	return tree -> val;
      else if(tree->left != NULL && tree->right == NULL)
	return (tree->val + maxRootLeaf(tree->left) );
      else if(tree->right != NULL && tree->left == NULL)
	return (tree->val + maxRootLeaf(tree->right));
      else 
	return (tree->val + max(maxRootLeaf(tree->left),maxRootLeaf(tree->right)));
    }

  }
public:
  TreeNode* createTree(){
    int data;
    TreeNode* root;
    cin >> data;
    if(data == -1)
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


int main()
{
  Solution s;
  TreeNode * root = s.createTree();
  int maxSum =  s.maxPathSum(root);
  cout << "Maximum of the path sum is : " << maxSum << endl;
  cin.get();
  getchar();
  return 0;
}
