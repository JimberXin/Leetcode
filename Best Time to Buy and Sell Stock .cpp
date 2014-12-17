//Last Modified: 2014/12/17
//Author: Junbo Xin

/*
//*********************************Problem Description*********************************
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock),
 design an algorithm to find the maximum profit.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if(prices.size() == 0)
      return 0;
    int minP = prices[0];
    int result = 0;
    for(int i=1; i < prices.size(); i++){
      result = max(result, prices[i] - minP);
      minP = min(minP, prices[i]);
    }
    return result;
  }
};

int main(void){
  Solution s;
  int arr[] = {2,1};
  vector<int> num;
  for(int i = 0; i<sizeof(arr)/sizeof(int);i++)
    num.push_back(arr[i]);
  int maxRes = s.maxProfit(num);
  cout << maxRes;
  getchar();
  return 0;
}
