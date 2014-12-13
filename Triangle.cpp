//Last Modified: 14/12/2014
//Author: Junbo Xin
#include<iostream>
#include<vector>
using namespace std;


/*
Given a triangle, find the minimum path sum from top to bottom.
Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space,
 where n is the total number of rows in the triangle.
*/

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();  //lines
    if(n==0) return 0;
    vector<int> dp(n,  INT_MAX);
    dp[0] = triangle[0][0];
    for(int i = 1; i < n; ++i){
      for(int j = i; j >=0; --j){
	if( j==0)
	  dp[j] = dp[0] + triangle[i][0];
	else 
	  dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
      }
    }
    int minSum = INT_MAX;
    for(int j=0; j < n; ++j){
      minSum = min(dp[j], minSum);
    }
    return minSum; 
  }
};

int main(){
  Solution s;
  vector<vector<int> > input;
  vector<int> line;
  line.push_back(2);
  input.push_back(line);
  line.clear();
  line.push_back(3);
  line.push_back(4);
  input.push_back(line);
  line.clear();
  line.push_back(6);
  line.push_back(5);
  line.push_back(7);
  input.push_back(line);
  line.clear();
  line.push_back(4);
  line.push_back(1);
  line.push_back(8);
  line.push_back(3);
  input.push_back(line);
  
  int result = s.minimumTotal(input);
  cout << result << endl;
  getchar();
  return 0;
}
