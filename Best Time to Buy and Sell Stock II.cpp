//Last Modified: 2014/12/17
//Author: Junbo Xin

/*
//************************************Problem Description****************************************
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times).
 However, you may not engage in multiple transactions at the same time
 (ie, you must sell the stock before you buy again).
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int start, end;
    if(prices.empty())
      return 0;
    start = end = prices[0];
    int maxRes  = 0;
    for(vector<int>::size_type i = 1 ; i< prices.size(); i++){ 
      if(prices[i] > end){
	end = prices[i];
	if( i == prices.size()-1)
	  maxRes += end -start;
      } else {
	maxRes += end - start;
	start = end = prices[i];
      }
    }
    return maxRes;
  }
};


int main(void){
  Solution s;
  int arr[] = {15};
  vector<int> num;
  for(int i = 0; i< sizeof(arr)/sizeof(int); i++)
    num.push_back(arr[i]);
  int result = s.maxProfit(num);
  cout << result << endl;
  getchar();
  return 0;
}
