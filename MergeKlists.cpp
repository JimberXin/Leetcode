#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 1000000
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
	ListNode(int x): val(x),next(NULL){}
};

struct Node
{
	int value;
	ListNode* from;
	Node(ListNode* node)
	 {
		   if(node==NULL)
			   value =  MAX;
		   else
			   value = node->val;
		   from = node;
	 }

	bool operator<(const Node& other) const
	{
		return value < other.value;
	}
	
	bool operator>(const Node& other) const
	{
		return value > other.value;
	}


};


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {
        //
             /*  int num = lists.size();
			   if(num == 0|| num == 1)
				     return num ==0 ? NULL: *lists.begin();
			   ListNode *newlist = *lists.begin();
			   vector<ListNode*>::iterator it;
			   for(it = ++lists.begin();it !=  lists.end(); it++)
				    newlist = merge2Lists(newlist,*it);
			   return newlist;  */
		      if(lists.size() == 0)
				  return NULL;
			  size_t size = lists.size();
			  vector<Node> heap;
			  for(size_t i=0; i< size;i++)
				  heap.push_back(Node(lists[i]));
			  make_heap(heap.begin(), heap.end(), greater<Node>());
		       ListNode* dummy = new ListNode(0);
			   ListNode* current = dummy;
			   pop_heap(heap.begin(),heap.end(),greater<Node>());
			   Node smallest = heap.back();
			   heap.pop_back();
			   while(smallest.value != MAX)
			   {
				      ListNode* next = smallest.from -> next;
					  current -> next = smallest.from;
					  smallest.from -> next = NULL;
					  current = current -> next;

					  heap.push_back(Node(next));
					  push_heap(heap.begin(), heap.end(),greater<Node>());
					  pop_heap(heap.begin(),heap.end(),greater<Node>());
					  smallest =  heap.back();
					  heap.pop_back();
			   }

			    ListNode* head = dummy->next;
				delete dummy;
				return head;
    
        //
    }
//public:
//	ListNode * merge2Lists(ListNode* l1, ListNode *l2)
//	{
//		      if(NULL == l1 ||  NULL == l2)
//				  return NULL == l1 ? l2: l1;
//			  ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
//			  ListNode * current = dummy;
//			  while(NULL != l1 && NULL != l2)
//			  {
//				     if( l1 -> val < l2 -> val)
//					 {
//						    ListNode * temp =  new ListNode(l1->val);
//							current -> next = temp;
//							current =  current -> next;
//		                    l1 = l1 -> next;
//					 }
//					 else
//					 {
//						    ListNode * temp =  new ListNode(l2->val);
//							current -> next = temp;
//							current =  current -> next;
//		                    l2 = l2 -> next;
//					 }
//			  }
//			  current -> next =  NULL == l1 ? l2:l1;
//			  return dummy -> next;
//	}
};


int main()
{
	 vector<ListNode*> all;
	 int arr1[] = { 1,3,5,7,9,12};
	 int arr2[] = { 4,6,16,21,32};
	 int arr3[] = {2,10,20,27,34};
 //**************list1*****************************
	 ListNode* pt, *current;
	  pt = (ListNode*)malloc(sizeof(ListNode));
	  current = pt;
	  for(int i= 0;i<sizeof(arr1)/sizeof(int);i++)
	  {
	     
            ListNode* temp =  new ListNode( arr1[i] );
			  current  -> next  = temp;
			  current =  current -> next;
	         }
	       current -> next  = NULL;
//**************list2*****************************
	 ListNode* pt2, *current2;
	  pt2 = (ListNode*)malloc(sizeof(ListNode));
	  current2 = pt2;
	  for(int i= 0;i<sizeof(arr2)/sizeof(int);i++)
	  {
	     
            ListNode* temp =  new ListNode( arr2[i] );
			  current2  -> next  = temp;
			  current2 =  current2 -> next;
	         }
	       current2 -> next  = NULL;

//**************list3*****************************
	 ListNode* pt3, *current3;
	  pt3 = (ListNode*)malloc(sizeof(ListNode));
	  current3 = pt3;
	  for(int i= 0;i<sizeof(arr3)/sizeof(int);i++)
	  {
	     
            ListNode* temp =  new ListNode( arr3[i] );
			  current3  -> next  = temp;
			  current3 =  current3 -> next;
	         }
	       current3 -> next  = NULL;

		   all.push_back(pt->next);
		   all.push_back(pt2->next);
		   all.push_back(pt3->next);
	 // number.push_back(num);
	  //int num[] = {1,7,6,3,4};
	  Solution s;
	 
  
	  //ListNode* newList = s.merge2Lists(pt->next, pt2->next);
	  ListNode* newList = s.mergeKLists(all);
	   while(NULL != newList)
	   {
		      cout <<  newList -> val << " ";
			  newList =  newList -> next;
	   }
	   cout <<  endl;
	  getchar();
	  return 0;
}