#include<iostream>
using namespace std;
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    //mark remains the nodes before the duplicates.
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode)); 
    if(head == NULL || head->next == NULL)
      return head;
    dummy -> next = head;
    ListNode* pre =  dummy;
    ListNode *cur =  pre -> next;
    ListNode* nex =  cur -> next;
    bool isSame  =  false;
    while(nex != NULL) {
      if(cur->val != nex->val) {
	if(isSame)
	  {
	    isSame = false;
	    pre -> next = nex;
	  }
	else
	  {
	    pre = cur;
	  }
	cur  = nex;
      }
      else
	isSame =  true;
      
      nex =  nex -> next;
    }
    // deal with the case that the end of the Nodes are also the duplicates
    if(isSame)
      pre -> next = NULL;
    return dummy->next;
  }
};

int main() {
  int num[] =  {3,3,2,2,2,2};
  // int num[] = {1,1,2,2,3,3,3,3,3,3,3,4,6,8,8};
  Solution s;
  ListNode* pt, *current;
  pt = (ListNode*)malloc(sizeof(ListNode));
  current = pt;
  int i;
  for(i=0;i<sizeof(num)/sizeof(int);i++)
    {
      ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
      tmp->val = num[i];
      current->next  = tmp;
      current =  current->next;
    }
  current->next  = NULL;
  // current -> next =  pt-> next -> next -> next ->  next;
  //printList(pt -> next);
  
  ListNode* newList = s.deleteDuplicates(pt->next);
  while(NULL != newList)
    {
      cout <<  newList -> val << " ";
      newList =  newList -> next;
    }
  cout <<  endl;
  getchar();
  return 0;
}
