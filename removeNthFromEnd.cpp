#include<iostream>
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
	 ListNode* next;
	 ListNode(int x): val(x),next(NULL){}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        //
                ListNode *second;
				ListNode* first = (ListNode*)malloc(sizeof(ListNode));
				ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
				first -> next = head;
				  dummy =  first;
			       second = head;
				if(NULL == head || NULL == head -> next)
					  return NULL;
				for(int i = 0; i< n; i++)
					  second = second -> next;
				while( NULL != second )
				{
					    first = first -> next;
						second = second -> next;
				}
				first -> next =  first -> next -> next;
				return dummy -> next;
        //
    }
};


int main()
{
	int num[] =  {3,1};
	 // int num[] = {1,1,2,2,3,3,3,3,3,3,3,4,6,8,8};
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
  
	  ListNode* newList = s.removeNthFromEnd(pt->next,2);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;
}