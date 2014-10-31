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