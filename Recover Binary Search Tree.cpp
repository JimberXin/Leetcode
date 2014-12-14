#include<iostream>

using namespace std;

/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  TreeNode* pre, *big,*small;
  void InorderTraverse(TreeNode* root) {
    if(root == NULL)
      return;
    InorderTraverse(root ->left);
    //********pre root value is bigger, mark s1 and s2 to be swapped
    if(pre != NULL && pre->val > root->val) {
      if(big == NULL)
	{
	  big = pre;
	  small = root;
	}
      else
	small = root;
    }
    pre = root;
    InorderTraverse(root->right);
  }

  void recoverTree(TreeNode *root) {
    if(root == NULL)
      return;
    pre = big = small = NULL;
    InorderTraverse(root);
    swap(big->val, small->val);
  }

TreeNode* createTree() {
  int data;
  TreeNode* root;
  cin >> data;
  if( data == -1)
    root = NULL;
  else
    {
      root = (TreeNode*)malloc(sizeof(TreeNode));
      root -> val = data;
      root -> left = createTree();
      root -> right = createTree();
    }
  return root;
 }

};

int main() {
  Solution s;
  TreeNode* root = s.createTree();
  s.recoverTree(root);
  getchar();
  return 0;
}
