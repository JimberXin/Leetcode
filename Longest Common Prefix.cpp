#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
          int n = strs.size();
		  string result;
		  if( n == 0) return result;
		  int idx = 0; // the minimum lengh of the strs
		  for(int i = 1; i < n; ++i)
			  if(strs[i].length() < strs[idx].length())
				  idx = i;
		  int maxLen = strs[idx].length();
		  for(int i = 0; i < n; ++i){
			   if( i == idx) continue;
			   int curLen = 0;
			   for(int j =0; j < strs[i].length() && j < maxLen; ++j)
			   {
				   if(strs[i][j] == strs[idx][j]) 
					   curLen ++;
				   else
					   break;
			   }
			   maxLen = curLen;
		  }
		  return strs[idx].substr(0, maxLen);
    }
};

int main(void){
	Solution s;
	string table[] ={"hello", "hel", "hellohello"};
	vector<string> input;
	for(int i = 0; i < 3; ++i)
		input.push_back(table[i]);
	string res = s.longestCommonPrefix(input);
	getchar();
	return 0;
}