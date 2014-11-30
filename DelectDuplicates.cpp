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
    ListNode *deleteDuplicates(ListNode *head) 
	{
          //
		        ListNode* cur, * pre, * nex;
				if(NULL ==  head || NULL == head -> next)
					  return head;
				pre =  head;
				cur = head -> next;
				while( NULL != cur)
				{ 
					 nex = cur -> next;
					 if( pre -> val == cur -> val)
						    pre -> next = nex;
					 else
					        pre = cur;
					  cur = nex;
				}
				return head;
		// 
     }
};


int main()
{
	  int num[] =  {1};
	  //int num[] = {1,2,2,3,3,3,3,3,3,3,4,6,8,8};
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
  
	  ListNode* newList = s.deleteDuplicates(NULL);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;
}