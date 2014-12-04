#include<iostream>
using namespace std;
#define max(a,b)((a)>(b)?(a):(b))


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
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL),right(NULL){}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if(NULL ==  root )
      return 0;
    else if( NULL ==  root -> left && NULL != root -> right)
      return 1 + maxDepth(root -> right);
    else if(NULL ==  root -> right && NULL != root ->left)
      return 1 + maxDepth(root->left);
    else if(NULL != root -> left && NULL != root -> right)
      return 1+max(maxDepth(root->left),maxDepth(root ->right));
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


int main()
{
  Solution s;
  TreeNode* root =  s.createTree();
  int depth = s.maxDepth(root);
  cout << " The depth of the tree is: " << depth << endl;
  cin.get();
  getchar();
  return 0;
}
