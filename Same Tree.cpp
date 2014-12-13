#include <iostream>

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

struct TreeNode{ 
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if( (NULL == p && NULL != q) ||  (NULL == q && NULL != p))
      return false;
    else if( NULL != p && NULL != q)
      if(p->val == q->val)
	return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
      else 
	return false;
    return true;   //Only when p and q are NULL
  }

public:
  TreeNode* createTree() {
    TreeNode *root;
    int data;
    cin  >> data;
    if(data == -1)
      root = NULL;
    else 
      {
	root = (TreeNode*) malloc(sizeof(TreeNode));
	root -> val = data;
	root  -> left=  createTree();
	root  -> right = createTree();
      }
    return root;
  }
};

int main(void) {
  Solution s;
  cout << " Please create the first tree: " << endl;
  TreeNode  *root1 =  s.createTree();
  cout << " Please create the second tree : " << endl;
  TreeNode  *root2 =  s.createTree();
  cout << " Whether they are the same tree: " ;
  cout <<  s.isSameTree(root1,root2);
  cin.get();
  getchar();
  return 0;
}
