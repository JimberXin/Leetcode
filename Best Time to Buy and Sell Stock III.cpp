//Last Modified: 2014/12/17
//Author: Junbo Xin

/*
//******************************Problem Description**************************************
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

//f1[i] records 0--i left max profit
//f2[i] records 0--i right max profit
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if( n == 0) return 0;
    vector<int> f1(n, 0);
    vector<int> f2(n, 0);
    int minV = prices[0];
    for(int i = 1; i < n; ++i){
      minV = min(minV, prices[i]);
      f1[i] = max(f1[i-1],  prices[i] - minV);			
    }

    int maxV = prices[n-1];
    for(int i = n-2; i >= 0; --i){
      maxV = max(maxV, prices[i]);
      f2[i] = max(f2[i+1], maxV - prices[i]);
    }
    
    int sum = 0;
    for(int i = 0; i < n; ++i)
      sum = max(sum, f1[i] + f2[i]);
    
    return sum;	   
  }
};

int main(){
  Solution s;
  int arr[] = {2, 4, 8, 3, 1, 9, 11, 7};
  vector<int> prices;
  for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
    prices.push_back(arr[i]);
  int res = s.maxProfit(prices);
  cout << res << endl;
  getchar();
  return 0;
}
