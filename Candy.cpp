#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
*/
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    if( n < 0) return 0;
    vector<int> candy(n, 1);
    //from begin to end, bottom is 1
    for(int i = 1; i < n; ++i){
      if(ratings[i] > ratings[i-1])
	candy[i] = candy[i-1] + 1;
    }
    //from end to begin, bottom is 1, top is the bigger one
    for(int i = n - 2; i >=0; --i){
      if(ratings[i] > ratings[i+1]){
	int temp = candy[i+1] + 1;
	candy[i] = max(candy[i], temp);
      }
    }
    int result = 0;
    for(int i = 0; i < n; ++i)
      result += candy[i];
    return result;
  }
};

int main(void){
  Solution s;
  int arr [] = {3,1,4,5,4,3,2,1,5,6};
  vector<int> input;
  for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
    input.push_back(arr[i]);
  int res = s.candy(input);
  cout << res << endl;
  getchar();
  return 0;
}
