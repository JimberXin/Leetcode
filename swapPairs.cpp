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

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        //
           ListNode* first, *second, *pre, *nex;
		   first = second = pre = head;
		   int i = 1;
		 while( NULL != first && NULL != first -> next)
		   {
			    second =  first -> next;
				nex = second -> next;
				first -> next =  nex;
				second -> next =  first;
				if(pre == head)
					head  =  second;
				else
					pre -> next  = second;
				// reseve the updated pointers
				pre =  first;
				first =  nex;
		   }
        return head;
        //
    }
};

int main()
{
	  //int num[] =  {1,2,3,4,5,6,7,8,9,12,32,0,32};
	  int num[] = {1};
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
  
	  ListNode* newList = s.swapPairs( NULL);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;
}