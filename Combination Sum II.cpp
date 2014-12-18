//Last Modified:  2014/12/18
//Author: Junbo Xin

/*
********************************Problem Description*********************************************
Given a collection of candidate numbers (C) and a target number (T),
 find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    sort(num.begin(),num.end());
    vector<vector<int> > result;
    vector<int> temp;
    DFS(num,target,0,temp,result);
    return result;
  }
  void DFS(vector<int>&num, int gap, int current, vector<int>  &temp, vector<vector<int> > &result)
  {
    if(gap == 0){
      result.push_back (temp);
      return;
    }

    int last = -1;  // mark last time vist

    for(size_t i= current; i< num.size(); ++i){
      if(last == num[i])  continue;   //make sure that the value has not yet been visited
      if(gap < num[i] )
	return;    //cut it down
      last = num[i];
      temp.push_back(num[i]);
      DFS(num,gap-num[i],i+1,temp,result); //the current index becomes i+1, not i
      temp.pop_back ();
    }
  }
};

int main(void)
{
  int arr[] = {10,1,2,7,6,1,5};
  Solution s;
  vector<int> num;
  for(int i=0; i< sizeof(arr)/sizeof(int);i++)
    num.push_back (arr[i]);
  vector<vector<int> > result = s.combinationSum2(num,8);
  vector<vector<int> >::iterator outside;
  vector<int>::iterator inside;
  for(outside=result.begin(); outside != result.end(); outside++){
    for(inside = outside -> begin(); inside != outside -> end(); inside++)
      cout << *inside << " " ;
    cout << endl;
  }
  getchar();
  return 0;
}
