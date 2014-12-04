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
