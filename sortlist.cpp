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
    ListNode *sortList(ListNode *head)
	{
		//
          ListNode*pre,* first, * second;
		   first = second = head;
		   if( NULL == head || NULL == head -> next)
			    return head;
		   while( NULL !=  second && NULL !=  second -> next)
		   {
			    pre = first;
			    first  =  first -> next;
				second = second -> next -> next;
		   }
		   pre -> next =  NULL;
		   second =  first;
		   first = head;
		   ListNode *newhead = mergeSort(sortList(first),sortList(second));
		   return newhead;
		   //
    }

public: 
	// list1 is saved as the final merged sort, list1 and list2 are two sorted linklist to be merged
	ListNode * mergeSort(ListNode* list1, ListNode* list2)
	{
			ListNode *p1,*p2 ,*p1_pre,*p2_nex;   //preseve the previous node of p1,and next node of p2
			p1  = list1;
			p1_pre  = NULL;
			p2  = list2;
			while( NULL != p1 && NULL  != p2)
			  { 

				    if( p1 -> val  <  p2 -> val )
					{
						  p1_pre = p1;
                          p1 = p1 -> next;
					}
					else
					{
						 p2_nex = p2 ->next ;
					     p2 -> next =  p1;
						 if(NULL == p1_pre)
							 list1 = p2;
						 else
						     p1_pre -> next = p2;
						 p1_pre = p2;
						 p2 = p2_nex;
					}
			  }
			if( NULL == p1)
				 p1_pre -> next = p2;
			return list1;
	        
	}
};

int main()
{
	 int num[] =  {7,3,1,6,3,4,43,54,8,7,9,12,32,0,52};
	  //int num[] = {1,7,6,3,4};
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
  
	  ListNode* newList = s.sortList(pt->next);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;
}