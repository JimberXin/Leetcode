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
	  ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        //
		     ListNode * newlist =  (ListNode*) malloc(sizeof(ListNode));
			 ListNode* current =  newlist;
              while( NULL != l1 && NULL != l2)
			  {
				      if(l1 -> val < l2 -> val)
					  {
						     ListNode* pt = (ListNode*)malloc(sizeof(ListNode));
							  pt -> val  = l1 -> val;
							  current -> next = pt;
							  current =  current -> next;
							  l1 =  l1 -> next;
					  }
					  else
					  {
						    ListNode* pt = (ListNode*)malloc(sizeof(ListNode));
							  pt -> val  = l2 -> val;
							  current -> next = pt;
							  current =  current ->next;
							  l2 =  l2 -> next;
					  }
			  }
			  if(NULL ==  l1)
				  current -> next = l2;
			  else
				  current -> next = l1;
			  return newlist -> next;
        //
        
    }
};
int main()
{
	  Solution s;

	  int num[] =  {2,4};
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

	  int num2[] = {1,2,4};
	    ListNode* pt2, *current2;
	  pt2 = (ListNode*)malloc(sizeof(ListNode));
	  current2 = pt2;
	  int j;
	  for(j=0;j<sizeof(num2)/sizeof(int);j++)
	  {
		     ListNode* tmp2 =  (ListNode*) malloc(sizeof(ListNode));
			  tmp2 -> val = num2[j];
			  current2  -> next  = tmp2;
			  current2 =  current2 -> next;
	  }
	    current2 -> next  = NULL;
	   // current -> next =  pt-> next -> next -> next ->  next;
		//printList(pt -> next);

  
	  ListNode* newList = s.mergeTwoLists(pt->next,NULL);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;
}