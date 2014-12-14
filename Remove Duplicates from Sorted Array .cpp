#include<iostream>
using namespace std;

/*
Given a sorted array, remove the duplicates in place such that each
 element appear only once and return the new length.

Do not allocate extra space for another array, 
you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if(n==0 || n==1)
      return n;
    int start = 0;
    int key = A[0];
    for(int i = 0; i<n; i++)
      if(A[i] != key)
	{
	  A[start++] = key;
	  key = A[i];
	}
    A[start ++]= key;
    
    return start;       
  }
};

int main() { 
  Solution s;
  int a[] ={1,1,2,2,2,2,2,2,3,3,3,3,3,3,4};
  int number = s.removeDuplicates(a,sizeof(a)/sizeof(int) );
  cout << endl << "Length of the array after removal is: "<<  number << endl;
  getchar();
  return 0;
}
