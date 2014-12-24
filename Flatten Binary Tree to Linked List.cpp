//Last Modified:  2014/12/21
//Author:   Junbo Xin

/*
******************************Problem Description*************************************
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
In the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
using namespace std;

struct TreeNode{ 
  int val;
  TreeNode*left;
  TreeNode* right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  void flatten(TreeNode *root){
    TreeNode* head = root;
    while(root != NULL){
      if(root->left != NULL){
	TreeNode* pt = root->left;
	while(pt->right != NULL)
	  pt = pt -> right;
	pt->right = root->right;
	root->right = root->left;
	root->left = NULL;
      }
      else
	root = root->right;
    }
    while(head != NULL){
      cout << head->val << " " ;
      head =  head->right;
    }
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
	root -> val = data;
	root -> left  = createTree();
	root -> right = createTree();
      }
    return root;
  }
};


int main()
{
  Solution s;
  TreeNode* root =  s.createTree();
  s.flatten(root);	 
  cin.get();
  getchar();
  return 0;
}

