#include<iostream>
#include<stdio.h>
using namespace std;

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
  ListNode* next;
  ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode* pSmall =  (ListNode*)malloc(sizeof(ListNode)) ;
    ListNode* pBig     =  (ListNode*)malloc(sizeof(ListNode));
    ListNode* pt = head;
    ListNode* small_head = pSmall;
    ListNode* big_head = pBig;
    if( NULL == head || NULL ==  head -> next)
      return NULL;
    while(NULL != pt){
      if(pt -> val < x){
	pSmall -> next = pt;
	pSmall = pSmall -> next;
      }	else {
	pBig -> next = pt;
	pBig = pBig -> next;
      }
      pt = pt -> next;
    }
    //judge whether big_head has elements
    pSmall -> next = ( big_head == pBig)? NULL: big_head -> next;
    pBig -> next = NULL;
    return small_head -> next;
  }
};

int main()
{
  //int num[] =  {8,2,3,45,5,6,13,9,12,32,0,35};
  int num[] = {4,1,0,2,2,2,2,4,0,4,2,3,1};
  Solution s;
  ListNode* pt, *current;
  pt = (ListNode*)malloc(sizeof(ListNode));
  current = pt;
  int i;
  for(i=0;i<sizeof(num)/sizeof(int);i++) {
    ListNode* tmp =  (ListNode*) malloc(sizeof(ListNode));
    tmp -> val = num[i];
    current  -> next  = tmp;
    current =  current -> next;
  }
  current -> next  = NULL;
   
  ListNode* newhead = s.partition(NULL, 7);	
  while(NULL != newhead) {
    cout <<  newhead -> val << " " ;
    newhead =  newhead -> next;
  }
  cout <<    endl;
  getchar();
  return 0;
}
