//Last Modified:  2014/12/25
//Author:   Junbo  Xin

/*
***********************Problem Description******************************
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()",
which has length = 2.

Another example is ")()())", where the longest valid parentheses substring
is "()()", which has length = 4.
*/


#include<iostream>
#include<string>
#include<stack>
using namespace std;

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
	if(j < length && s[j] == ')'){
	  dp[i] = dp[i+1]+2;
	  if(j+1 < length)
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


