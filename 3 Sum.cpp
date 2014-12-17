//Last Modify: 2014/12/17
//Author: Junbo Xin

//********************************Problem Description***********************************
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(),num.end());
    vector<vector < int> > result;
    vector<int> temp;
    int last_1 = INT_MIN;
    int last_2 = INT_MIN;
    for(int i=0;i<num.size(); i++)
      {
	if(last_1 == num[i] && last_1 !=0) continue;
	if(num[i] > 0) break;
	last_1 = num[i];
	temp.push_back (num[i]);
	for(int j = i+1; j< num.size();j++)
	  { 
	    if(last_2 == num[j] && last_1 !=0) continue;
	    if(num[i]+num[j] > 0)  break;
	    temp.push_back (num[j]);
	    last_2 = num[j];
	    for(int k = j+1; k< num.size(); k++)
	      {
		if(num[i] + num[j]+num[k] > 0) break;
		// find a solution here
		if(num[i] + num[j] + num[k] == 0)
		  {
		    temp.push_back (num[k]);
		    //deal with the case that have many 0
		    if( result.empty() || *(--result.end()) != temp)
		      result.push_back (temp);
		    temp.pop_back ();//now has two elements in temp
		    break;
		  }
	      }
	    temp.pop_back ();    /// now has one element in temp
	  }
	temp.pop_back();  // now has no element in temp
      }
    return result;						    
  }

  void DFS(vector<int> &num, int index1, int index2, int target,vector<int> &temp,vector<vector<int> > &result)
  {
    if(target == 0)
      {
	result.push_back(temp);
	return;
      }
    for(int i = index1; i<num.size();i++)
      {
	if(num[i] > target)   return;
	temp.push_back (num[i]);
	for(int j = index2; j < num.size();j++)
	  {
	    if(num[j] > target)   return;
	    temp.push_back(num[j]);				
	    DFS(num,i,j,target-num[i]-num[j],temp,result);
	  }
      }
  }
};
int main()
{
  Solution s;
  int arr[] ={ 0,0,0,0,0};
  vector<int> num;
  for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    num.push_back (arr[i]);
  vector<vector<int> > result = s.threeSum(num);	
  vector<vector<int> >::iterator outside;
  vector<int>::iterator inside;
  for(outside = result.begin(); outside != result.end(); outside ++)
    {
      for(inside =  outside->begin(); inside != outside->end(); inside++)
	cout << * inside << " ";
      cout <<  endl;
    }
  getchar();
  return 0;
}
