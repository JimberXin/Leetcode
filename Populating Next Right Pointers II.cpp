#include<iostream>
using namespace std;
/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode* left, *right, *next;
  TreeLinkNode(int x): val(x),left(NULL),right(NULL),next(NULL){}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if(root == NULL)
      return;
    TreeLinkNode *leftBegin = root;
    TreeLinkNode *level;
    TreeLinkNode *pre;
    TreeLinkNode *last;
    while(leftBegin != NULL) {
      level = leftBegin;
      last = leftBegin;
      pre = NULL;
      while(level != NULL) {
	if(level->left != NULL && level->right != NULL)
	  {
	    if(pre != NULL)
	      pre->next = level->left;
	    else
	      leftBegin = level->left;
	    level->left->next = level->right;
	    pre = level->right;
	  }
	else if(level->left == NULL && level->right != NULL)
	  {
	    if(pre != NULL)
	      pre->next = level->right;
	    else
	      leftBegin = level->right;
	    pre = level->right;
	  }
	else if(level->right == NULL && level->left != NULL)
	  {
	    if(pre != NULL)
	      pre->next = level->left;
	    else
	      leftBegin = level->left;
	    pre = level->left;
	  }
	level = level -> next;
      }
      if(last == leftBegin )  // in the same level, break
	break;
    }        
  }


TreeLinkNode* createTree()
  {
    int data;
    cin >> data;
    TreeLinkNode* root;
    if(data == -1)
      root = NULL;
    else
      {
	root =  new TreeLinkNode(data);
	root -> left = createTree();
	root -> right = createTree();
      }
    return root;
  }
};

int main(void)
{
  Solution s;
  TreeLinkNode* root = s.createTree();
  s.connect(root);
  getchar();
  return 0;
}
