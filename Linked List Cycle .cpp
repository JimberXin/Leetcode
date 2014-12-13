/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    struct ListNode*  slow, *fast;
    slow =  fast = head;
    if( NULL ==  head || NULL ==  head -> next)
      return false;
    while(fast != NULL && fast -> next != NULL)
      {
	fast =  fast -> next -> next;
	slow = slow -> next;
	if(fast == slow)
	  return true;
      }
    return false;
  }

public:
  ListNode *detectCycle(ListNode *head) {
    struct ListNode*  slow, *fast;
    slow =  fast = head;
    if(head == NULL || head->next == NULL)
      return NULL;
    while(fast != NULL && fast->next != NULL) {
      fast =  fast -> next -> next;
      slow = slow -> next;
      if(fast == slow)
	break;
    }
    if(fast == NULL || fast->next == NULL)
      return NULL;
    slow =  head;
    while(slow != fast)
      {
	fast = fast -> next;
	slow = slow -> next;
      }
    return slow;
  }
};

void printList(ListNode* head) {
  while(head != NULL) {
    cout <<  head -> val << " " ;
    head = head -> next;
  }
  cout << endl;
}
int main() {
  //int num[] =  {1,2,3,4,5,6,7,8,9,12,32,0,32};
  int num[] = {1,2};
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
  bool isCircle = s.hasCycle(pt->next);
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


void recursion(ListNode* head) {
  if(head == NULL)
    return;
  if(head->next != NULL)
    recursion(head->next);
  cout<< head->val <<"\t";
}
