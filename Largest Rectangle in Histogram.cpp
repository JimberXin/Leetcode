//Last Modified:  2014/12/23
//Author:   Junbo Xin

/*
******************************Problem Description*******************************
Given n non-negative integers representing the histogram's bar height where
the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/



#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
      stack<int> stk;
      height.push_back(0);// dummy element, to end the calculation
      int i = 0;
      int maxArea = 0;  //important, when height is empty, also valid
      while(i < height.size()){
	if(stk.empty() || height[stk.top()] <= height[i]){
	  stk.push(i++);
	} else {
	  int temp = stk.top();
	  stk.pop();
	  maxArea = max(maxArea, height[temp] * (stk.empty()? i: i-stk.top()-1));
	}
      }
      return maxArea; 
    }		
};

int main(void){
  Solution s;
  int arr[] = {2,1,5,6,2,3};
  vector<int> heig;
  for(int i=0; i<sizeof(arr)/sizeof(int);i++)
    heig.push_back(arr[i]);
  int maxA =s.largestRectangleArea(heig);
  getchar();
  return 0;
}
