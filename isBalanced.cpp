#include<iostream>
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
struct TreeNode { 
  int val;
  TreeNode *left;
  TreeNode* right;
  TreeNode(int x):val(x), left(NULL),right(NULL){}
};

class Solution {
public:
  bool isBalanced(TreeNode *root){
    if(NULL == root)
      return true;
    if(abs( height(root -> left)- height(root->right) ) >1 )
      return false;
    else
      return (isBalanced( root ->left) && isBalanced(root ->right));
  }

public:
  int height(TreeNode* nodes){
    if(NULL ==  nodes)
      return 0;
    else
      {
	int leftHeight =  height(nodes->left);
	int rightHeight =  height(nodes -> right);
	return 1+((leftHeight > rightHeight)? leftHeight: rightHeight);
      }
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
  bool isBalance = s.isBalanced(root);
  if(isBalance)
    cout << " This is a balanced tree! " << endl;
  else
    cout << "This is not a balanced tree!" << endl;

  cin.get();
  getchar();
  return 0;
}
