#include<vector>
#include<iostream>
using namespace std;

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

/**
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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  struct ListNode* findMiddle(struct ListNode* head){
    struct ListNode* first, *second, *pre;
    pre = first = second = head;
    if(NULL== head || head->next == NULL)
      return head;
    else {
      while(second != NULL && second->next != NULL ){
	pre = first;
	first = first -> next;
	second = second -> next->next;
      }
      second = first;
      pre->next = NULL;
      first = head;
      return second;  
    }
  }
  
  //reverse the totall Linklist 'head' without extra space
  struct ListNode* reverse(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur= head;
    struct ListNode* nex=  NULL;
    while(cur != NULL){
      nex = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nex;
    }
    head->next = NULL;
    head = pre;
    return pre;
}

  void reorderList(ListNode *head){
    if(head == NULL)   return;
    else {
      struct ListNode* mid =  findMiddle(head);
      mid = reverse(mid);	                 
      // return the List reversed from the middle
      struct ListNode* head_nex, *mid_nex;
      head_nex = mid_nex = NULL;
      struct ListNode* newlist = head;
      if(head ==  mid)   ;
      else
	while(head != NULL  && mid != NULL){
	  head_nex = head->next;
	  mid_nex =  mid->next;                 
	  //insert the second element into the first Linklist
	  mid->next = (head->next == NULL)?mid->next:head->next;    
	  head->next = mid;   
	  head = head_nex;
	  mid = mid_nex;
	}  
    }  
  }
};

int main(){
  Solution s;
  int arr[] = {3,2,25,5,1,12,23,0,8,4,7};
  ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
  ListNode* cur = dummy;
  for(int i=0; i< sizeof(arr)/sizeof(int); ++i){
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp->val = arr[i];
    cur->next = temp;
    cur = cur->next;
  }
  cur->next = NULL;
  s.reorderList(dummy->next);
  ListNode* p = dummy->next;
  while(p != NULL){
    cout << p->val << " " ;
    p = p->next;
  }
  getchar();
  return 0;
}
