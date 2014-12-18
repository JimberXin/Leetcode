//Last Modified:  2014/12/19
//Author:  Junbo Xin

/*
*************************************Problem Description**************************************
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/



#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if( s.empty() ) return 0;
    int n = s.length();
    vector<int> dp(n, 0);  // dynamic programming
    //memset( dp, 0, sizeof(dp) );
    dp[n-1] = s[n-1] == '0'? 0:1;
    for(int i = n-2; i >= 0; --i)
      {
	if(s[i] == '0')
	  dp[i] = 0;
	else if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
	  {
	    if( i == n -2)
	      dp[i] = dp[i+1] + 1;
	    else
	      dp[i] = dp[i+1] + dp[i+2];
	  }
	else 
	  dp[i] = dp[i+1];
      } // end for 
    return dp[0];
  }
};

int main(void){
  Solution s;
  string str = "120382425";
  int num = s.numDecodings(str);
  cout << num << endl;
  getchar();
  return 0;
}
