//Last Modified: 2014/12/23
//Author:  Junbo Xin

/*
*****************************Problem Description********************************
Given an array of non-negative integers, you are initially positioned at
 the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include<iostream>
using namespace std;

class Solution {
public:
  bool canJump(int A[], int n) {
    int max = 0;
    for(int i=0; i < n && i <= max; i++)
      max = A[i] + i > max ? A[i]+i: max;
    return max >= n-1;
    }
};

int main(void){
  Solution s;
  int arr[] = {2,3,1,1,4};
  bool isTrue = s.canJump(arr,sizeof(arr)/sizeof(int));
  getchar();
  return 0;
}
