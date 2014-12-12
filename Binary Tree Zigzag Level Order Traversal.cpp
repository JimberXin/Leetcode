#include<iostream>
#include<vector>
#include<queue>
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
  TreeNode* right;
  TreeNode(int x): val(x),left(NULL), right(NULL){}
};

class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > all;
    vector<int> pair;
    queue<TreeNode*> nodes;
    int curnum =1;
    int nextnum = 0;
    if(NULL == root)
      return all;
    nodes.push(root);
    pair.push_back(root -> val);
    all.push_back(pair);
    pair.clear();
    while( ! nodes.empty()){
      root = nodes.front();   // delEnqueue
      nodes.pop();
      curnum --;

      if(NULL != root ->left){
	nodes.push(root -> left);
	pair.push_back( root->left ->val);
	nextnum ++;
      }
      if(NULL != root->right){
	nodes.push(root -> right);
	pair.push_back(root ->right ->val);
	nextnum++;
      }

      if( 0 == curnum){
	if(!pair.empty())
	  all.push_back(pair);
	pair.clear();
	curnum = nextnum;
	nextnum = 0;
      }
    }
    vector<vector<int> >::iterator it;
    int flag = 1;
    for(it = all.begin();it != all.end(); it++){
      if(flag == -1)
	reverse(it ->begin(),it->end());
      flag *= -1;
    }
    return all; 
  }

public:
  TreeNode* createTree(){
    TreeNode* root;
    int data;
    cin >> data;
    if( data == -1)
      root = NULL;
    else{
      root =  new TreeNode(data);
      root -> left   =  createTree();
      root -> right =  createTree();			 
    }
    return root;
  }
};

int main()
{
  Solution s;
  TreeNode* root = s.createTree();
  vector< vector<int> > zigzag = s.zigzagLevelOrder(root);
  vector< vector <int> >::iterator outside;
  vector<int>:: iterator inside;
  for(outside = zigzag.begin(); outside != zigzag.end(); outside++){
    for(inside = outside -> begin(); inside !=  outside -> end(); inside++)
      cout << *inside << " ";
    cout << endl;
  }
  cin.get();
  getchar();
  return 0;
}
	
