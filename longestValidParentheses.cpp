#include<iostream>
#include<string>
#include<stack>
using namespace std;

//*******************DP ****************
class Solution {
public:
  int longestValidParentheses(string s) {
    int maxLen =0,i,j,k;
    int length =  s.length();
    int *dp = new int[length];
    memset(dp,0,sizeof(dp)*length);
    for(i = length-2; i >=0; i--) {
      if(s[i] == '(') {
	j = i+1+dp[i+1];
	if( j < length && s[j] == ')'){
	  dp[i] = dp[i+1]+2;
	  if( j+1 < length)
	    dp[i] += dp[j+1];
	}
      }
      maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
  }
};

int main(void)
{
  Solution s;
  string str = "(((()(()";
  int len = s.longestValidParentheses(str);
  cout << len << endl;
  getchar();
  return 0;
}


