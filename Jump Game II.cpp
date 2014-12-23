//Last Modified:  2014/12/23
//Author:  Junbo Xin

/*
****************************Problem Description********************************
Given an array of non-negative integers, you are initially positioned 
at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include<iostream>
using namespace std;

class Solution {
public:
  int jump(int A[], int n) {
    int *dp = new int[n];
    if(n ==0 ) return INT_MIN;
    for(int i =0; i < n; i++)
      dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i = 1; i < n; i++){
      for(int j = 0 ; j < i; j++){
	if(A[j] + j >= i){
	  if(dp[j] + 1 < dp[i]) {
	    dp[i] = dp[j] + 1;
	    break;
	  }
	}
      }
    }
    return dp[n-1];
  }
};

int main(void){
  Solution s;
  int arr[] ={ 2,3,1,1,4};
  int res = s.jump(arr,sizeof(arr)/sizeof(int));
  getchar();
  return 0;
}
