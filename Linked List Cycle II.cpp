//Last Modified:  2014/12/23
//Author:  Junbo Xin

/*
********************Problem Description*********************
Given a linked list, return the node where the cycle begins.
 If there is no cycle, return null.

Follow up:
Can you solve it without using extra 

 * Definition for singly-linked 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast, *slow;
    if(head == NULL || head->next == NULL) return NULL;
    fast = slow = head;
    while(fast != NULL && fast->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
      if(fast == slow) break;
    }
    if(fast == NULL ||fast->next == NULL)
      return NULL; 
    slow = head;
    while(slow != fast){
      slow = slow->next;
      fast = fast->next;
    }
    return slow;  
  }
};

int main(void){
  //int num[] =  {1,2,3,4,5,6,7,8,9,12,32,0,32};
  int num[] = {1,2};
  Solution s;
  ListNode* pt, *current;
  pt = (ListNode*)malloc(sizeof(ListNode));
  current = pt;
  int i;
  for(i=0;i<sizeof(num)/sizeof(int);i++){
    ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
    tmp -> val = num[i];
    current  -> next  = tmp;
    current =  current -> next;
  }
  current -> next  = NULL;
  // current -> next =  pt-> next -> next -> next ->  next;
  //printList(pt -> next);
  bool isCircle = s.detectCycle(pt->next);
  ListNode* cycleBegin = s.detectCycle(pt -> next);
  cout << " Whether it is a cycle: " <<  isCircle  << endl;
  if (cycleBegin == NULL) 
    cout << "No cirle  in the Linklist "  << endl;
  else
    cout << " Where the cycle begins: " << cycleBegin ->val << endl;
  cout << sizeof(num)/sizeof(int)<< endl;
  
  getchar();
  return 0;
}
