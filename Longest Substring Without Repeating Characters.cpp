//Last Modified:  2014/12/25
//Author: Junbo Xin

/*
**********************************Problem Description********************************
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s){
    int start = 0;
    int maxLength = 0;
    bool flag[256];
    int position[256];
    memset(flag,0,sizeof(flag));
    memset(position,0,sizeof(position));
    for(int i=0; i< s.size();i++) {
      //*****Already exist, delect all the char before where it emerges
      if(flag[s[i]-' '])
	{
	  for(int j=start; j < position[s[i]-' ']; j++)
	    flag[s[j]-' '] = false;
	  start = position[s[i]-' '] + 1;
	  position[s[i]-' '] = i;
	  flag[s[i]-' '] = true;
	}
      //***************go on traversal*********************
      else
	{
	  position[s[i]-' '] = i;
	  flag[s[i]-' '] = true;
	  maxLength = max(maxLength, i-start +1);
	}
    }
    return maxLength;
  }
};

int main(void)
{
  Solution s;
  string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsar
                cbynecdyggxxpklorellnmpapqfwkhopkmco";
  int length = s.lengthOfLongestSubstring(str);
  cout << length << endl;
  getchar();
  return 0;
}
