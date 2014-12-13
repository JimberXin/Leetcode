#include<iostream>
#include<stack>

using namespace std;

/*
Given a binary tree containing digits from 0-9 only, 
each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
  TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    int result = 0;
    int sum = 0;
    stack<TreeNode*> nodeStack;
    TreeNode* last = NULL;
    while(root != NULL || !nodeStack.empty())
      {
	while(root != NULL)
	  {
	    nodeStack.push(root);
	    result = 10*result + root -> val;
	    root = root -> left;
	  }
	root = nodeStack.top();
	// if the right has been visited, visit the curent node
	if(root->right == NULL || last == root->right) {
	  if(root->left == NULL && root->right == NULL)
	    sum += result;
	  last = root;
	  result /= 10;
	  nodeStack.pop();
	  root = NULL;					
	}
	else  // if the right node has not visited, visit it
	  root = root -> right;  					  
      }
    return sum;      
  }

  TreeNode* createTree() {
    int data;
    TreeNode* root;
    cin >> data;
    if(data == -1)
      root = NULL;
    else {
      root = new TreeNode(data);
      root -> left  = createTree();
      root -> right = createTree();
    }
    return root;
  }
};

int main(void)
{
  // Solution s;
  // TreeNode* root = s.createTree();
  //int result = s.sumNumbers(root);
  // cout << result << endl;
  getchar();
  cin.get();
  return 0;
}
	  
