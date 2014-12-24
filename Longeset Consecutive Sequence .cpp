//Last Modified: 2014/12/24
//Author:  Junbo Xin

/*
***********************************Problem Description***************************
Given an unsorted array of integers,
 find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    map<int,bool>  Hash;
    int maxNum = 0;
    for(int i=0; i< num.size(); i++)
      Hash[num[i]] = true;
    for(int j=0; j < num.size(); j++){
      if(Hash[num[j]]){
	Hash[num[j]] = false;
	int count = 1;
	int left = num[j] -1,  right = num[j] + 1;
	while(Hash.find(left) != Hash.end() ){
	  Hash[left--] = false;
	  count ++;
	}
	while( Hash.find(right) != Hash.end()){
	  Hash[right++] = false;
	  count++;
	}
	maxNum = max(maxNum, count);
      }
    }
    return maxNum;
  }
};

int main(void){
  Solution s;
  int arr[] = {100,3,5,4,2,1,300,6};
  vector<int> num;
  for(int i = 0; i< sizeof(arr)/sizeof(int); i++)
    num.push_back(arr[i]);
  int res = s.longestConsecutive(num);
  getchar();
  return 0;
}
