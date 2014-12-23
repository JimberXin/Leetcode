//Last Modified:  2014/12/23
//Author:  Junbo Xin

/*
********************************Problem Description*********************************
Given a string s consists of upper/lower-case alphabets and empty space'
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#include<iostream>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int count = 0;
    int lastlength = 0;
    const char* prev = s;
    while(*s != '\0'){
      if(*s == ' ')
	{
	  if(*prev != ' ') lastlength = count;
	  count = 0;
	}
      else
	count++;
      prev = s;
      s++;
    }
    return *prev == ' '? lastlength: count;
  }
};

int main(void){
  Solution s;
  const char* str = " a  ";
  int res = s.lengthOfLastWord(str);
  cout << res << endl;
  getchar();
  return 0;
}
