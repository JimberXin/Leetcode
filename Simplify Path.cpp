#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> name;
    string result;
    int n = path.length();
    if(n == 0 || path == "/") 
      return path;
    string temp;
    for(int i = 1; i < n; ++i)
      {
	while( i < n && path[i] != '/')
	  temp += path[i++];
	if(temp == "..")
	  {
	    if( !name.empty())
	      name.pop_back();
	  }
	else if( !temp.empty() && temp != ".")
	  name.push_back(temp);
	temp.clear();
      }
    if( name.empty()) 
      result = "/";
    for(int i = 0; i < name.size(); ++i)
      result += "/" + name[i];
    return result;
  }
};

int main(){
  Solution s;
  string s1 ="/home/jimber/./a/../Xin/";
  string s2 = "/home//foo/";
  string res1 = s.simplifyPath(s1);
  string res2 = s.simplifyPath(s2);
  return 0;
}
