#include<iostream>
#include<vector>
#include<algorithm>

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
  TreeNode(int x): val(x), left(NULL),right(NULL){}
};
class Solution {
public:
  //unsigned int count;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
    /*
    TreeNode* root;
    count ++;
    TreeNode* node= (TreeNode*) malloc(sizeof(TreeNode));
    if( preorder.empty() )
      return NULL;
    vector<int>::iterator pre,in;
    pre = preorder.begin();  //find the root in preorder
    in = find(inorder.begin(),inorder.end(),*pre); //find the root in inorder
    node -> val = *pre;
    if(preorder.size() == 1){
        node -> left = node -> right = NULL;
        return node;
     }
      //*******************no left child************************
    else  if( in == inorder.begin()){
         vector<int> preRight(++pre, preorder.end());
	 vector<int>inRight(++in,inorder.end());
	 node -> left  = NULL;
	 node -> right = buildTree(preRight, inRight);
      }  
      //**********************no  right child****************************
    else  if( *in == inorder.back()) {
         vector<int> preLeft(++pre,preorder.end());
	 vector<int> inLeft(inorder.begin(), in); //not  --in
	 node -> right =  NULL;
	 node -> left = buildTree(preLeft,inLeft);
	 }
      //******************both left child an right childe exist*******************
     else {
           //should use the numbers, not the iterator
	   //in_pre = find(preorder.begin(),preorder.end(),*(--in)); //find the middle of the preorder
	   vector<int>::iterator it2 = preorder.begin();
	   //it2 marks the middle of preorder
	   for(vector<int>::iterator it1= inorder.begin();  it1 != in;  it1++,it2++); 
	       vector<int> inLeft(inorder.begin(),in); 
	       vector<int> inRight(++in,inorder.end());
	       vector<int> preLeft(++pre,++it2);
	       vector<int> preRight(it2, preorder.end());
	       node -> left =  buildTree(preLeft, inLeft);
	       node -> right =  buildTree(preRight,inRight);
	     }
	     //return node;		       
    */
    return 0 == preorder.size()?NULL:createTreeTemp(preorder.begin(), preorder.end(),
						    inorder.begin(), inorder.end() );

  }
  
  TreeNode* createTreeTemp(vector<int>::iterator preL,vector<int>::iterator preR,
			   vector<int>::iterator inL, vector<int>::iterator inR){
    if(preL >= preR) 
      return NULL;
    int value = *preL;
    TreeNode *root = new TreeNode(value);
    vector<int>::iterator in = find(inL,inR,value);
    vector<int>::size_type num = in - inL;

    root -> left = createTreeTemp(preL+1,preL+num+1,inL,in);
    root -> right = createTreeTemp(preL+num+1,preR,in+1,inR);
    return root;
  }

public:
  void preorderTraversal(TreeNode *root){
    if(NULL != root){
      cout << root -> val << " " ;
      preorderTraversal( root -> left);
      preorderTraversal( root -> right);
    }
  }

  void inorderTraversal(TreeNode* root){
    if(NULL != root){		      
      inorderTraversal( root -> left);
      cout << root -> val << " " ;
      inorderTraversal( root -> right);
    }
  }
};


int main()
{ 
  Solution s;
  vector<int> pre, in;
  // int a[]= {3,2,1,4};
  //int b[]= {1,2,3,4};
  int a[] = {9,-6,7,5,3,8,11};
  int b[] = {7,-6,5,9,8,3,11};
  int length = sizeof(a)/sizeof(int);
  for(int i=0;i<length;i++){
    pre.push_back(a[i]);
    in.push_back(b[i]);
  }
  TreeNode* root = s.buildTree(pre,in);
  cout << "Preorder of the created tree is: ";
  s.preorderTraversal(root);
  cout << endl <<  "Inorder of the created tree is: ";
  s.inorderTraversal(root);
  getchar();
  return 0;
}
