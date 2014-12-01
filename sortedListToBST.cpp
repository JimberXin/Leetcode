#include<iostream>
#include<vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x): val(x),next(NULL){}
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x),left(NULL),right(NULL){}
};

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) 
  {
    //
    int n = getListLength(head);
    TreeNode *root = buildBST(head,0,n-1);
    return root;
    //
  }

  int getListLength(ListNode* head)
  {
    if(NULL == head)
      return  0;
    int count = 0;
    while(NULL != head)
      {
	head = head -> next;
	count ++;
      }
    return count;
  }
  
  TreeNode* buildBST(ListNode* &head, int begin, int end)
  {
    if(begin > end)
      return NULL;
    int mid = begin + (end -begin)/2;
    TreeNode *left = buildBST(head,begin,mid-1);
    TreeNode *root = new TreeNode(head -> val);
    head = head -> next;
    TreeNode *right = buildBST(head,mid+1,end);
    root -> left = left;
    root -> right = right;
    return root;
  }
};


int main()
{
  //int num[] =  {8,2,3,45,5,6,13,9,12,32,0,35};
  int num[] = {1,2,3,4};
  Solution s;
  ListNode* pt, *current;
  pt = (ListNode*)malloc(sizeof(ListNode));
  current = pt;
  int i;
  for(i=0;i<sizeof(num)/sizeof(int);i++)
    {
      ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
      tmp -> val = num[i];
      current  -> next  = tmp;
      current =  current -> next;
    }
  current -> next  = NULL;
  TreeNode* newroot = s.sortedListToBST(pt->next);	
  getchar();
  return 0;
}
