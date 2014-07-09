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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        //
		int flag = 0;
		ListNode* pt = (ListNode*)malloc(sizeof(ListNode));
		ListNode *current = pt;
		if( NULL == l1 || NULL ==  l2) 
			return NULL == l1?l2:l1;
        while( NULL != l1 && NULL !=l2)
		{		  
			  ListNode*  temp =  new ListNode( ( l1 -> val + l2->val +flag)%10 );
			  current -> next =  temp;
			  current = current -> next;
			   flag = (l1 -> val + l2 -> val +flag) / 10;
			  l1 =  l1 -> next;
			  l2 =  l2 -> next;

		}
		//****************both of l1 and l2 are NULL*******************
		  if(NULL == l1 && NULL == l2)
		  {
			    if(flag ==1)
				{
					  ListNode* temp =  new ListNode(1);
					  current  -> next =  temp;
					  current =  current ->next;
				}
				current -> next = NULL;
		  }  
		  else
		  {
			  ListNode * listtemp;
		  //************************l2 is NULL**************************************
		   if(NULL ==  l2)
		   {
			   ListNode* temp =  new ListNode (( l1 -> val + flag)%10);
			   flag  =  (l1 -> val + flag) /10;
			    current -> next = temp;
				listtemp = l1;
		   }
		  //*************************l1 is NULL*******************************************
		   else 
		    {
			       ListNode* temp =  new ListNode (( l2 -> val + flag)%10);
				    flag  =  (l2 -> val + flag) /10;
			        current -> next = temp;
					listtemp = l2;
		    }
			   if( 0 == flag)
				   current -> next  -> next = listtemp -> next;
	      //************************deal wih the case that overflows***********************
			   else  
			   {
				      //current =  current -> next;
					  while( NULL != listtemp && listtemp -> val == 9)
					    {
						   ListNode* temp =  new ListNode(0);
						   current -> next = temp;
						   current =  current -> next;
						   listtemp = listtemp ->next;
					    }
					   if(NULL== listtemp)
					   {
						   ListNode *temp =  new ListNode(1);
					       current -> next = temp;
						   current ->next -> next =  NULL;
					   }
					   else
					   {
						     ListNode * temp = new ListNode( listtemp -> val +1);
							 current ->  next =  temp;
							 current = current -> next;
							 current -> next = listtemp -> next;
					   }					 
			   }

		  }
				   

		   return pt -> next;
        
        //
    }
};


int main()
{
	 Solution s;

	  int num[] =  {9,2};
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

	  int num2[] = {3,7};
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

  
	  ListNode* newList = s.addTwoNumbers(pt->next, pt2->next);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;

	 
}
