#include<iostream>
#include<string>
using namespace std;


//Given a string, determine if it is a palindrome,
//considering only alphanumeric characters and ignoring cases. For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//Have you consider that the string might be empty?
//This is a good question to ask during an interview.
//For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
public:
    bool isPalindrome(string s){
      int length = s.length();
      if(length == 0)
	return true;
      int i,j;
      for(i=0, j=length-1; i< j; ++i,--j){
	while((s[i]<'0' || (s[i]>'9'&&s[i]<'A') || (s[i]>'Z'&&s[i]<'a') || s[i]>'z') && i<j)
	  ++i;
	while((s[j]<'0' || (s[j]>'9'&&s[j]<'A') || (s[j]>'Z'&&s[j]<'a') || s[j]>'z') && j>i )
	  --j;
	if (i == j) 
	  return true;
	// both s[i] and s[j]  are numbers
	if(s[i] <= '9' && s[j] <= '9')
	  {
	    if(s[i] == s[j]) 
	      continue;
	    else  
	      return false;
	  }
	// both s[i]  and s[j]  are alphs
	else if(s[i] >= 'A' && s[j] >= 'A')
	  {
	    if(s[i]== s[j] || (abs(s[i] - s[j]) == 32) )
	      continue;
	    else
	      return false;
	  }
	else
	  return false;
      }
      return true;
    }
};

int main(void) {
  Solution s;
  //string str = "A man, a plan, a canal: Panama";
  string str = "aA";
  bool isValidPalindrome = s.isPalindrome(str);
  cout << "Whether it is a palindrome: " << isValidPalindrome << endl;
  getchar();
  return 0;
}
