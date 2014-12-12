#include<iostream>
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

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &num)
  {
    return buildBST(num,0,num.size()-1);  
  }

  TreeNode *buildBST(vector<int>&num, int begin, int end)
  {
    if(begin > end)
      return NULL;
    int mid = begin + (end - begin)/2;
    TreeNode* left = buildBST(num,begin,mid-1);
    TreeNode* right = buildBST(num,mid+1,end);
    TreeNode *root = new TreeNode(num[mid]);
    root -> left = left;
    root -> right = right;
    return root;
  }
};

int main()
{
  Solution s;
  vector<int> num;
  int arr[] ={ 1,2,3,4,5};
  for(int i=0; i<sizeof(arr)/sizeof(int);i++)
    num.push_back(i);

  TreeNode *root = s.sortedArrayToBST(num);
  getchar();
  return 0;
}
