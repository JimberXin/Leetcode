#include<iostream>
#include<vector>
#include<stack>
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
  vector<int> postorderTraversal(TreeNode *root){
    vector<int> values;
    stack<TreeNode*> BSstack;
    TreeNode *last =  NULL;
    // Traversing the left nodes of T	 
    while(NULL != root || !BSstack.empty()){
      // Traversing the left nodes of root
      while( NULL != root){
	BSstack.push(root);
	root = root -> left;
      }
      root =  BSstack.top();
      // visit root node
      if(NULL == root -> right || last == root -> right){
	last  = root;
	values.push_back(root ->val);
	BSstack.pop();
	root = NULL;
      } else
	root = root ->right;
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
  TreeNode *root =  s.createTree();
  vector<int> post = s.postorderTraversal(root);
  for(vector<int>::iterator it = post.begin();it !=post.end(); it ++)
    cout << *it << " " ;
  cout << endl;
  cin.get();
  getchar();
  return 0;
}
