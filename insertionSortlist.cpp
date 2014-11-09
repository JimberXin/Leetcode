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
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head)
    {
        //last remains the already sorted list.
             ListNode* pre,*cur,*nex, *key,*last;
			 if( NULL == head || NULL == head -> next)
				 return head;
			 last = head;
			 key = head -> next;
			 while(NULL != last )
			 {
			         pre = NULL;
					 cur =  head;
					 key = last -> next;
					 if( NULL ==  key)
						  return head;
					 else
					      nex = key -> next;
			    while( cur != last && key -> val >= cur -> val)
			          {
                        pre = cur;
						cur = cur -> next;
			          }
			    if( key -> val <  cur -> val)
			      {
					    last -> next = nex;
				      key -> next = cur;
					  if( NULL ==  pre)
						  head = key;
					  else
					    pre -> next  = key;
			      }
				else
					 last = key;
			 }

			 return head;

        //
    }
};


int main()
{
	  //int num[] =  {1,2,3,4,5,6,7,8,9,12,32,0,52};
	  int num[] = {4,19,14,5,-3,1,8,5,11,15};
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
  
	  ListNode* newList = s.insertionSortList(pt->next);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;
}