#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;

//Design and implement a data structure for Least Recently Used (LRU) cache. 
//It should support the following operations: get and set.
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
//it should invalidate the least recently used item before inserting a new item.

class LRUCache{
public:
	struct Node{
		Node* pre;
		Node* nex;
		int key;
		int value;
		Node():pre(NULL), nex(NULL),key(-1), value(-1){};
		Node(int k, int v): pre(NULL), nex(NULL), key(k), value(v){};
	};

    LRUCache(int c) {
         if(c < 0) return;
		 head = new Node();
		 tail = new Node();
		 hashTable.clear();
		 head -> nex = tail;
		 tail -> pre = head;
		 capacity = c;
		 size = 0;
    }
    
    int get(int key) {
          unordered_map<int, Node*>::iterator it = hashTable.find(key);
		  if( it == hashTable.end() )
			    return -1;
		  //recently used the key, move it to the head
          Node* p = it -> second;
		  p -> nex -> pre  = p -> pre;
		  p -> pre -> nex = p -> nex;
		  addToHead(p);
		  return p -> value ;	
    }
    
    void set(int key, int value) {
        if(capacity < 1) return;
		unordered_map<int, Node*>::iterator it = hashTable.find(key);
		//the node is already in the cache
		if( it != hashTable.end()){
			  Node* p = it -> second;
			  p -> nex -> pre = p -> pre;
			  p -> pre -> nex = p -> nex;
			  addToHead(p);
			  p -> value = value;
		}else{ // the node is not yet in the cache
			   Node* p = new Node(key, value);
			   addToHead(p);
			   hashTable.insert(pair<int,Node*>(key, p));
			   ++size;
			   //reach the capacity, invalidate the least recently used item
			   if(size > capacity){
				    p = tail -> pre;
					tail -> pre = p -> pre;
					p -> pre -> nex = tail;
					it = hashTable.find(p->key);
					hashTable.erase(it);
					delete p;
			   }
		}//end else
    }

	void addToHead(Node* p){
		  p -> nex = head -> nex;
		  head -> nex -> pre = p;
		  head -> nex = p;
		  p -> pre = head;
	}
private:
	int capacity;
	int size;
	unordered_map<int, Node*> hashTable;
	Node* head;  // head and tail are both dummy node
	Node* tail;
};


int main(){
	/*
	int arr[] = {2,3,4,5};
	int n = sizeof(arr)/sizeof(int);
	LRUCache L(7);
	for(int i = 0; i < n; ++i)
		L.set(arr[i],2*arr[i]);
	L.set(6,12);
	L.set(7,14);
	L.set(8,16);
	L.set(9,18);
	*/
	LRUCache L(2);
	L.set(2,1);
	L.set(2,2);
	L.get(2);
	L.set(1,1);
	L.set(4,1);
	L.get(2);
	getchar();
	return 0;
}