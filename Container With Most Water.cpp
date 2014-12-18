//Last Modified:  2014/12/19
//Author: Junbo Xin

/*
*************************Problem Description*****************************************
Given n non-negative integers a1, a2, ..., an, where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line 
i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int m= height.size();
    if( m ==0 || m == 1)
      return 0;
    int maxA = 0;
    int i = 0, j = m -1;
    while(i < j){
      if(height[i] < height[j]){
	  maxA =   max( maxA, height[i]*(j-i) );
	  i++;
      } else {
	maxA = max( maxA, height[j]*(j-i) );
	j--;
      }		     
    }
    return maxA;
  }
};

int main(void)
{
  Solution s;
  int arr[] = {8,3,5,6,4,7};
  vector<int> numbers;
  for(int i=0; i< sizeof(arr)/sizeof(int); i++)
    numbers.push_back(arr[i]);
  int result = s.maxArea(numbers);
  cout << result << endl;
  getchar();
  return 0;
}
