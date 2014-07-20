#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	
    int minCut(string s) 
    {
        //	
		  size_t length = s.length();
		  int *dp = new int[length];
		  bool **isPalindrome = new bool*[length];
		  for(int i=0; i < length;i++)
			  dp[i] = length - i;
		  for(int i =0; i<length; i++)
		  {
			     isPalindrome[i] = new bool[length];
				 memset(isPalindrome[i], 0, length*sizeof(bool) );
		  }
		  for(int i = length - 1; i>=0; i--)
		  {
			    for(int j=i; j< length; j++)
				{
					   if(s[i] == s[j] &&(j-i < 2 || isPalindrome[i+1][j-1]))  //make sure it is a Palindrome
					   {
						    isPalindrome[i][j] = true;
							dp[i] = j==length-1? 1: min(dp[i], dp[j+1]+1);
					   }
				}
		  }
		  return dp[0]-1 ;       
        //        
    }
};

int main()
{
	Solution s;
	string str = "a";
	int mincut = s.minCut(str);
	cout << mincut;
	getchar();
	return 0;
}