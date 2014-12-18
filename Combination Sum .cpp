//Last Modified: 2014/12/18
//Author: Junbo Xin

/*
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// reference of mannual c++ pp.156-pp.157
class Solution {
public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target){
    sort(candidates.begin(),candidates.end());
    vector<vector<int> > result;
    vector<int> temp;
    DFS(candidates,target,0,temp,result);
    return result;    
  }

  void DFS(vector<int> nums, int gap, int current, vector<int> &temp, vector<vector<int> > &result){
    // find onde solution
    if(gap == 0){ 
      result.push_back(temp);
      return;
    }
    for(size_t i=current;i<nums.size();i++){
      if(gap < nums[i])
	return;  // cut it down
      temp.push_back(nums[i]);
      DFS(nums,gap-nums[i],i,temp,result);
      temp.pop_back();
    }		   
  }
};

int main(void)
{
  Solution s;
  int arr[] = {2,7,6,3};
  vector<int> num;
  vector< vector<int> > result;
  for(int i=0; i<sizeof(arr)/sizeof(int);i++)
    num.push_back(arr[i]);
  result = s.combinationSum(num,7);
  vector<vector<int> > :: iterator it;
  for(it = result.begin(); it != result.end(); it++){
    for(vector<int>::iterator inside = it->begin(); inside != it->end(); inside++)
      cout << *inside << " " ;
    cout << endl;
  }
  getchar();
  return 0;
}
