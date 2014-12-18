//Last Modified:  2014/12/19
//Author:  Junbo Xin

/*
*******************************Problem Description**************************
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/


#include<iostream>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string result;
    if(n <= 0) 
      return result;
    result = "1";
    string lastStr = result;
    for(int i = 1; i < n; ++i){
      lastStr = result;
      result.clear();
      int len = lastStr.length();
      for(int j = 0; j < len; ++j){
	int count = 1;
	while(j < len -1 && lastStr[j] == lastStr[j+1]){
	  ++j;
	  ++count;
	}
	result += count  + '0';
	result += lastStr[j];
      }
    }
    return result;
  }
};

int main(void){
  Solution s;
  string res = s.countAndSay(9);
  getchar();
  return 0;
}
