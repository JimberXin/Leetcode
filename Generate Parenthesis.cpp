//Last Modified:  2014/12/22
//Author:   Junbo Xin

/*
*************************************Problem Description**************************
Given n pairs of parentheses, write a function to generate all combinations of 
well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
  void generate(int leftNum, int rightNum, string s, vector<string> &result)
  {
    if(leftNum == 0 && rightNum ==0)
      {
	result.push_back(s);
	return;
      }
    if(leftNum >0)
      generate(leftNum-1, rightNum, s+'(', result);
    if(rightNum > 0 && leftNum < rightNum)
      generate(leftNum,rightNum-1, s+')',result);
  }
			       
  vector<string> generateParenthesis(int n) {
    string str;
    vector<string> all;
    generate(n,n,str,all);
    return all;
  }
};

int main(void) {
  vector<string> result;
  Solution s;
  result = s.generateParenthesis(2);
  vector<string>::iterator it;
  for(it= result.begin(); it != result.end(); it++)
    cout << *it<< " " ;
  cout<< endl;
  getchar();
  return 0;
}
