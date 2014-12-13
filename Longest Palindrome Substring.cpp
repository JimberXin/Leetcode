#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
  string preProcess(string s) {
    size_t length = s.length();
    string result;
    if(length == 0)
      result = "^#";
    else
      result = "^";
    for(int i=0; i < length;i++)
      result += "#" + s.substr(i,1);
    result += "#$";
    return result;
  }
  string longestPalindrome(string s){
    //Using Manacher Algorithm
    //  ^ # b # a # b # c # b # a  # b # c #  b # a # c # c # b # a # $
    //      0 1 0 3 0 1 0 7 0 1 0 9 0 1 0 5 0 1 0 1 0 1 2 1 0 1 0 1 0
    string newStr = preProcess(s);
    size_t length = newStr.length();
    int *P = new int[length];
    int center =1;
    int Right = 0;
    for(size_t i= 1; i < length-1; i++)
      {
	int i_mirror =  2*center - i;
	if(Right > i)
	  P[i] = (Right - i) > P[i_mirror]? P[i_mirror]: Right - i;
	else
	  P[i] = 0;
 
	while (newStr[i+P[i]+1] == newStr[i-P[i]-1])//continues to expand
	  P[i]++;
	if(i + P[i] > Right)
	  {
	    Right =  i + P[i];
	    center = i;
	  }
      }
    int maxLen = 0;
    int index = 0;
    for(int i =1; i< length -1; i++)
      {
	if(maxLen < P[i])
	  {
	    maxLen = P[i];
	    index = i;
	  }
      }
    delete[] P;		   
    return s.substr( (index - maxLen -1)/2, maxLen) ;    
  }
};

int main(void)
{
  Solution s;
  string str = "3";
  //string str = "babcbabcbaccba" ;
  string result = s.longestPalindrome(str);
  cout << result << endl;
  getchar();
  return 0;
}
