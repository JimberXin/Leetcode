#include<iostream>
using namespace std;
//Given two sorted integer arrays A and B, merge B into A as onesorted array.
//You may assume that A has enough space (size that is greater or equal to m + n)
//to hold additional elements from B. The number of elements initialized in A
//and B are m and n respectively.

class Solution {
public:
  void merge(int A[], int m, int B[], int n)
  {
    int i = m-1;
    int j = n-1;
    while(i>=0 && j>=0)
      {
	if(A[i] > B[j])
	  A[i+j+1] = A[i--];
	else
	  A[i+j+1] = B[j--];
      }
    if(i <= 0)
      while(j>=0)
	A[j] = B[j--];
  }
};

int main(void)
{
  Solution s;
  int A[17] = {4,6,7,8};
  int B[12] = { };
  s.merge(A,4,B,sizeof(B)/sizeof(int));
  getchar();
  return 0;
}

