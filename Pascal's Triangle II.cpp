#include<iostream>
#include<vector>
using namespace std;

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    result.push_back(1);
    unsigned long long temp = 1;
    int numerator = rowIndex;;
    int denominator = 1;
    while( numerator > 0){
      temp  = temp  * numerator-- / denominator++;
      result.push_back(temp);
    }
    return result;        
  }
};

int main(void) {
  Solution s;
  vector<int> res = s.getRow(34);
  getchar();
  return 0;
}
