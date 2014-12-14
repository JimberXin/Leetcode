#include<iostream>

using namespace std;

/*
Given an array and a value, remove all instances of that value 
in place and return the new length.

The order of elements can be changed. 
It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    if(n==0)  return n;
    int start = 0;
    //int key = A[0];
    for(int i=0; i<n;i++)
      if(A[i] != elem)
	A[start++] = A[i];
    return start;
  }
};

int main() {
  int a[]= {2};
  Solution s;
  int length = s.removeElement(a,sizeof(a)/sizeof(int),3);
  cout << endl <<  "Length of the new array is: " <<  length;
  getchar();
  return 0;
}
