#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<string>
using namespace std;

class Solution {
public:
  void DFS(string s, int index, vector<string> &result, vector<string> &temp, 
	   unordered_set<string> &dict,vector<vector<bool> > isMatch)
  {
    int n = s.length();
    if(index >= n ){
      string ret;
      for(int i =0; i < temp.size(); i++)
	ret += temp[i] + " " ;
      ret.pop_back();
      result.push_back(ret);
    }

    for(int len = 1; len <= n - index; len++)
      {
	string prefixstr = s.substr(index,len);
	if( dict.count(prefixstr) >0 &&  ( (index+len) == n || isMatch[n-index-len][index+len] ) )
	  {
	    temp.push_back(prefixstr);
	    DFS(s, index+len, result, temp, dict, isMatch);
	    temp.pop_back();
	  }
      }
  }

  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    //
    int n = s.length();
    //m[len][start]:from the index:start, len numbers
    vector<vector<bool> > isMatch(n+1, vector<bool>(n+1, false)); 
    int maxLen, minLen;
    unordered_set<string>::iterator it = dict.begin();
    for(int i=0; i <= n; i++)
      isMatch[0][i] = false;
    for(int len = 1; len <= n; len++){
      for(int start = 0; start <= n - len; start++){
	if(dict.count(s.substr(start,len)) >0 )
	  isMatch[len][start] = true;
	else
	  {
	    for(int k = 1; k < len; k++){
	      isMatch[len][start] = isMatch[k][start] && isMatch[len-k][start+k];
	      if( isMatch[len][start] ) break;
	    }
	  }
      }
    }

    vector<string> result;
    vector<string> temp;
    if(!isMatch[n][0]) 
      return result;
    DFS(s,0,result,temp, dict,isMatch);
    return result;
    //
  }
};

int main(void){
  Solution s;
  string arr1[] = {"cat", "cats", "and", "sand", "dog"};
  string str = "catsanddog";
  unordered_set<string> dictinary;
  for(int i =0 ; i < 5; i++)
    dictinary.insert(arr1[i]);
  vector<string> res = s.wordBreak(str,dictinary);
  getchar();
  return 0;
}
