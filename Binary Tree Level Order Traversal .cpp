//Last Modified: 2014/12/17
//Author: Junbo Xin

/*
//*****************************Problem Description*************************
Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, 
where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
 
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x),left(NULL), right(NULL){}
};
class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    queue<TreeNode*> q;
    vector< vector<int> >  values;
    vector<int> pair;
    // curNum is the current levels' total nodes number;
    //nextNum is the next level's total nodes number
    int curNum = 1;
    int nextNum = 0;
    if(root == NULL)
      return values ; // return [];
    q.push(root);
    pair.push_back(root->val);
    values.push_back(pair);
    pair.clear();
    while(!q.empty()){
      root = q.front();
      q.pop();
      --curNum;				   
      if(root->left != NULL){
	q.push(root->left);
	pair.push_back(root->left->val);
	++nextNum;
      }
      if(root->right != NULL){
	q.push(root->right);
	pair.push_back(root->right->val);	
	++nextNum;
      }     		  
      if(curNum == 0){
	if(!pair.empty() )
	  values.push_back(pair);
	pair.clear();
	curNum = nextNum;
	nextNum = 0;
      }
    }
    return values;        
  }

public:
  TreeNode* createTree(){
    int data;
    TreeNode* root;
    cin >> data;
    if(data == -1)
      root = NULL;
    else
      {
	root = (TreeNode*) malloc(sizeof(TreeNode));
	root->val = data;
	root->left = createTree();
	root->right = createTree();
      }
    return root;
  }
};

int main()
{
  /*vector<vector < int> > outside;
    vector<int> inside;
    vector< vector<int> > ::iterator it;
    it =  outside.begin();
    inside.push_back(1);
    inside.push_back(2);
    inside.push_back(3);
    outside.push_back(inside);
    inside.clear();
    inside.push_back(4);
    inside.push_back(5);
    outside.push_back(inside);*/
  Solution s;
  TreeNode* root = s.createTree();
  vector< vector<int> > output =  s.levelOrder(root);
  cin.get();
  getchar();
  return 0;
}
