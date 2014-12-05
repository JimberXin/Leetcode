#include<iostream>
#include<stack>
#include<vector>

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
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root){
    vector<int> values;
    stack<TreeNode*> BSstack;
    while( NULL != root || !BSstack.empty()){
      while(NULL != root){
	// cout << root -> val << " ";
	values.push_back(root -> val);
	BSstack.push(root);
	root = root -> left;
      }

      root = BSstack.top();
      BSstack.pop();
      root =  root -> right;
    }
    return values;
  }

public:
  TreeNode* createTree(void){    
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

int main()
{
  Solution s;
  TreeNode* root =  s.createTree();
  vector<int> pre = s.preorderTraversal(root);
  for(vector<int>::iterator it = pre.begin(); it != pre.end(); it++)
    cout << *it << " " ;
	 
  cin.get();
  getchar();
  return 0;
}
