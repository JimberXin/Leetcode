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
    //   find onde solution
    if(gap == 0){ 
      result.push_back(temp);
      return;
    }
    for(size_t i=current;i<nums.size();i++){
      if(gap < nums[i])
	return ;  // cut it down
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
