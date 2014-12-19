//Last Modified:  2014/12/20
//Author:  Junbo Xin

/*
****************************Problem Description***************************
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &num) {
    int n = num.size();
    if(n == 1)
      return num[0];
    int left = 0;
    int right = n - 1;
    int mid = 0;
    while(num[left] >= num[right]){
      if(right - left == 1)
	return num[right];
      mid = left + (right - left)/2;
      if( num[right] >= num[mid] )
	right = mid;
      else if(num[left] <= num[mid])
	left = mid;
    }
    return num[mid];
  }
};

int main(){
  Solution s;
  int arr[] = {9,12,18,19,24, 25,53,0,3};
  vector<int> num;
  for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
    num.push_back(arr[i]);
  int findM = s.findMin(num);
  cout << findM << endl;
  getchar();
  return 0;
}
