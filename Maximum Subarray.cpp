//Last Modified:  2015/01/10
//Author:   Junbo Xin

/*
****************************Problem Description*********************************
Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

If you have figured out the O(n) solution, try coding another solution using
 the divide and conquer approach, which is more subtle.
*/

#include<iostream>
using namespace std;

class Solution {
public:
  int maxSubArray(int A[], int n) {
    int *d = new int[n];
    if(n == 0) return 0;
    d[0] = A[0];
    int result = d[0];
    for(int i = 1; i < n ; i++){
      d[i] = max(d[i-1] + A[i], A[i]);
      if(d[i] > result)
	result = d[i];
    }     
    return result;
  }
};

int main(void)
{
  Solution s;
  int A[] = { -2,1,-3,4,-1,2,1,-5,4};
  int result = s.maxSubArray(A,sizeof(A)/sizeof(int));
  getchar();
  return 0;
}
