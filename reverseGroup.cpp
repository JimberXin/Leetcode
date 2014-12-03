#include < iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *pt,*pre,*nex,*first,*second;
    pre = NULL;
    pt = head;
    int count = 1;
    if( NULL ==  head ||  NULL == head -> next)
      return head;
    while( NULL != pt){
      first = pt;
      while( count % k &&  NULL != pt){
	pt = pt -> next;
	count ++;
      }
      // If the number of nodes is not a multiple of k then left-out
      //nodes in the end should remain as it is
      if( NULL == pt)
	break;  
      second = pt;
      nex = pt -> next;
      ListNode * newhead = reverse(first, second);
      if (NULL ==  pre)
	head = newhead;
      else
	pre -> next = newhead;    
      first -> next = nex;
      pre =  first;
      pt = nex;	
      count ++; 
    }
    return head;
  }


public:
  ListNode *reverse(ListNode* first, ListNode* second) {
    ListNode* pre, *cur, * nex;
    pre =  NULL;
    cur =  first;
    while( second !=  cur) {
	nex =  cur ->  next;
	cur -> next = pre;
	pre = cur;
	cur = nex;
      }
    cur -> next = pre;
    return cur;
  }
};


int main()
{
  //int num[] =  {1,2,3,4,5,6,7,8,9,10,11,12,32};
  int num[] = {1,2,3,4,5};
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

  ListNode* newList = s.reverseKGroup(pt -> next,5);
  while(NULL != newList) {
    cout <<  newList -> val << " ";
    newList =  newList -> next;
  }
  cout <<  endl;
  getchar();
  return 0;
}
