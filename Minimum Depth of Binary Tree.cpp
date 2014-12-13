#include <iostream>

using namespace std;
#define min(a,b)((a)<(b)?(a):(b))

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
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
  int minDepth(TreeNode *root) {
    if(root == NULL)
      return 0;
    else if(root->left != NULL && root->right != NULL)
      return 1 + min(minDepth(root->left),minDepth(root->right));
    else if(root->left == NULL && root->right != NULL)
      return 1 + minDepth(root->right);
    else if(root->right == NULL && root->left != NULL)
      return 1 + minDepth(root->left);
    else
      return 1;
  }

public:
  TreeNode* createTree() {
    TreeNode* root;
    int data;
    cin >> data;
    if(data ==  -1)
      root =  NULL;
    else {
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root -> val = data;
	root -> left = createTree();
	root -> right =  createTree();
    }
    return root;
  }
};

int main() {
  Solution s;
  TreeNode* root =  s.createTree();
  int depth = s.minDepth(root);
  cout << " The minimum depth of the tree is:  " <<  depth <<  endl;
  cin.get();
  getchar();
  return 0;
}
