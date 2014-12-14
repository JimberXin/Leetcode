#include<iostream>
using namespace std;
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *pt, * pre, *nex, *first, *second;
    int count  = 0;
    pre = NULL;
    pt =  head;
    if( NULL == head || NULL == head->next)
      return head;
    
    while((m-1) != count) {
	pre = pt;
	pt =  pt->next;
	count ++;
      }
    first  = pt;
    ListNode *pre_tmp, *cur_tmp, * nex_tmp;
    pre_tmp = NULL;
    cur_tmp = pt;
    while(n != count && cur_tmp != NULL) {
      nex_tmp = cur_tmp -> next;
      cur_tmp -> next = pre_tmp;
      pre_tmp = cur_tmp;
      cur_tmp =  nex_tmp;
      count ++;
    }
    second = pre_tmp;
    nex = cur_tmp;
    if(pre == NULL)
      head = second;
    else
      pre  -> next = second;
    first -> next = nex;
    return head;
  }
};
int main()
{
  // int num[] =  {1,2,3,4,5,6,7,8,9,12,32,0,52};
  int num[] = {1,2,3,4,5,6};
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
  // current -> next =  pt-> next -> next -> next ->  next;
  //printList(pt -> next);
  
  ListNode* newList = s.reverseBetween(pt->next,3,4);
  while(NULL != newList){
    cout <<  newList -> val << " ";
    newList =  newList -> next;
  }
  cout <<  endl;
  getchar();
  return 0;
}
