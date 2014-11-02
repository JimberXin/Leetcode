#include<iostream>
#include<vector>
using namespace std;
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
       RandomListNode* cur= head ;
	   RandomListNode* nex;
	   if(head == NULL)
		   return NULL;
	   //******add new node after the old node*******
	   while(NULL != cur){
		      nex = cur -> next;
			  RandomListNode* node = new RandomListNode(cur ->label);
			  node -> next = nex;
			  cur -> next = node;
			  cur = nex;
	      }
	      cur = head;
		  while(NULL != cur){
			     if(NULL != cur->random)
					   cur -> next -> random = cur ->random -> next;
				 cur = cur -> next -> next;
		  }
		  cur = head;
		  RandomListNode* newhead = head -> next;
		  RandomListNode* cur2 = newhead;
		  while(NULL != cur){
			  nex = cur -> next -> next;
			  cur2 = cur -> next;
			  cur -> next = nex;
			  if(NULL != nex)
			     cur2 -> next = nex -> next;
			  cur = nex;	   
    }
		    return newhead;
	}
};

int main(void){
       Solution s;
	   RandomListNode *dummy = (RandomListNode*)malloc(sizeof(RandomListNode));
	   RandomListNode * current = dummy;
	   int arr[] = {1,2,3,4,5};
	   for(int i=0; i<sizeof(arr)/sizeof(int);i++)
	   {
		      RandomListNode* temp = new RandomListNode(arr[i]);
			  current -> next = temp;
			  current = current -> next;
	   }
	   current -> next = NULL;

	   RandomListNode* newList = s.copyRandomList(dummy->next);
	   getchar();
	   return 0;
}