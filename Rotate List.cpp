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

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) 
  {
    //
    ListNode  *pt, *first, * second;
    pt =  first =  second = head;
    int length = 0;
    if(head == NULL || NULL == head -> next) 
      return head;
    while(NULL != pt)
      {
	pt = pt -> next;
	length ++;
      }
    k %= length;
    for(int i=0; i < k; i++)
      {
	if( NULL == second )
	  return head;
	else
	  second =  second-> next;
      }
    while(NULL != second && NULL !=  second -> next)
      {
	first =  first -> next;
	second =  second -> next;
	length ++ ;
      }
    if(  NULL == second) 
      return head;
    second -> next = head;
    head =  first -> next;
    first -> next =  NULL;
    return head;
    //
  }

};


int main()
{
  //int num[] =  {1,2,3,4,5,6,7,8,9,12,32,0,52};
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
  // current -> next =  pt-> next -> next -> next ->  next;
  //printList(pt -> next);
 
  ListNode* newList = s.rotateRight(pt->next,8);
  while(NULL != newList)
    {
      cout <<  newList -> val << " ";
      newList =  newList -> next;
    }
  cout <<  endl;
  getchar();
  return 0;
}
