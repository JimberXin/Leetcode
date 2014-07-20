#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
	  bool isPal[1000][1000];
	  bool visited[1000];  //visited records wheter after S[i] has been apart
	   vector<vector<string>> result;

public:
     void DFS(string s, int index)
	 {
		 //***********Travesal over the end of the string, deal with it *************
		    if(index == s.length())
			  {
				     vector<string>  each;
					 string temp;
					 for(int k = 0; k<s.length(); k++)
					 {
						      temp += s[k];
							  if(visited[k])
							  {
								  each.push_back(temp);
								  temp.clear();
							  }
					 }
					 result.push_back(each);
					 return;
			  }

			for(int i = index; i < s.length(); i++)
			{
				    if(isPal[index][i])
					{
						    visited[i] = true;
							DFS(s,i+1);
							visited[i] = false;
					}
			}
	 }

    vector<vector<string>> partition(string s)
    {
		memset(isPal,0,sizeof(isPal));
		memset(visited,0,sizeof(visited));
		int i,j,k;
		//*******isPal[][]**records whether s[i]~s[j] is a Palindrome********
		for( i =0; i< s.length(); i++)
		 {
			  for(j = i; j< s.length(); j++)
			    {
				    for(k = 0; k < (j - i +1)/2; k++)
						  if(s[i +k] != s[j-k])     break;
					  isPal[i][j] =  k== (j-i+1)/2?true:false;
			    }
		 }
		      DFS(s,0);
		      return result;	
    }
};

int main(void)
{
	Solution s;
	string str = "abcddcba";
	vector<vector<string>> result = s.partition(str);
	getchar();
	return 0;
}