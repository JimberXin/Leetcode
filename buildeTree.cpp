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
struct TreeNode
{
	 int val;
	 TreeNode * left;
	 TreeNode *right;
	 TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        //
            
        	return 0 == postorder.size()?NULL:buildTreeHelper(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
        //      
    }
	TreeNode *buildTreeHelper(vector<int>::iterator inL,     vector<int>::iterator inR,
		                                             vector<int>::iterator posL, vector<int>::iterator posR)
	{
		       if( posL>= posR)
				   return NULL;
			   int value = *(--posR);
			   TreeNode * root = new TreeNode(value);
			   vector<int>::iterator in = find(inL,inR,value);
			   int num = in - inL;
			   root -> left = buildTreeHelper(inL,in,posL,posL+num);
			   root -> right = buildTreeHelper(in+1,inR,posL+num,posR);

			   return root;
	}
};

int main(void)
{
	Solution s;
	vector<int> in,post;
	//int num1[] = { 8,3,17,6,7,9,12,11,10};
	//int num2[] = {8,17,3,7,6,12,10,11,9};
	int num1[] ={2,1};
	int num2[] ={2,1};
	for(int i= 0; i< sizeof(num1)/sizeof(int);i++)
	{
		in.push_back(num1[i]);
		post.push_back (num2[i]);
	}
	TreeNode * root = s.buildTree(in,post);
	 
	getchar();
	return 0;
}