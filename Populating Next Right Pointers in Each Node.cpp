#include<iostream>
#include<vector>

using namespace std;

/*
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
 and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

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
  TreeLinkNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode* leftBegin = root;
    if(root == NULL) return;
    TreeLinkNode* curLevel ;
    while(leftBegin != NULL){
      curLevel = leftBegin;
      while(curLevel != NULL)
	{
	  if(curLevel->left != NULL)
	    curLevel->left-> next = curLevel->right;		
	  if(curLevel->right != NULL)
	    curLevel->right->next = curLevel->next == NULL? NULL:curLevel->next->left;
	  curLevel = curLevel->next;
	}
      leftBegin = leftBegin->left;
    }       
  }

TreeLinkNode* createTree() {
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
  cin.get();
  getchar();
  return 0;
}
	  
