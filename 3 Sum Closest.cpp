//Last Modified: 2014/12/17
//Author: Junbo Xin

//*********************************Problem Description********************************
/*
Given an array S of n integers, find three integers in S such that the sum is closest 
to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	
  int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    bool flag = true;  // Only use at first time
    int result;  //save the closest sum to target
    for(int i = 0;  i < num.size(); i++){
      int first = i + 1 ;
      int second = num.size() - 1;
      while( first < second){
	int sum = num[i] + num[first]+ num[second];
	if(flag){
	  result = sum;
	  flag = false;
	}  else {
	  if( abs(result - target) > abs(sum - target) )
	    result = sum;
	}
	if( result == target)
	  return result;
	//************set two pointers first and seoncd
	if(sum > target)
	  second --;
	else
	  first ++;
      }
    }
    return result;
  }
};

int main(void){
  Solution s;
  int arr[] = {-1,3,2,5,-2,4,12};
  vector<int> num;
  for(int i=0; i< sizeof(arr)/sizeof(int); i++)
    num.push_back(arr[i]);
  int res = s.threeSumClosest(num,4);
  cout << res << endl;
  getchar();
  return 0;
}
