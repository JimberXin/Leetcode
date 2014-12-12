#include<iostream>
#include<string>
#include<vector>
using namespace std;

//*****************Interleaving String******************************
//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//For example, Given:
//s1 = "aabcc",
//s2 = "dbbca",
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.

//****Solution****
//isPart[i][j] is a bool array, means now in s3: s1 has i elements, s2 has j elements
//For the initilization, if j==0, which denotes that s2 has no elments in s3, 
//all the elements in s3 are the same with s1, if s1[i] != s3[i], just break out. Same case if i==0
//For the state shift problem, isPart[i][j] can departed into two cases:
//1) s1[i-1] == s3[i+j-1] and isPart[i-1][j] is true.     or
//2) s2[j-1] == s3[i+j-1] and isPart[i][j-1] is true.

class Solution{
public:
  bool isInterleavingString(string s1, string s2, string s3){
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    if(n1+n2 != n3) return false;
    if(n1==0) return !s2.compare(s3);
    if(n2==0) return !s1.compare(s3);
    vector<vector<bool> > isPart(n1+1, vector<bool>(n2+1,false));
    isPart[0][0] = 1;
    for(int i = 0; i < n1; ++i){
      if(s1[i] == s3[i])
	isPart[i+1][0] = true;
      else break;
    } 
    for(int j = 0; j < n2; ++j){
      if(s2[j] == s3[j])
	isPart[0][j+1] = true;
      else break;
    }
    
    for(int i = 1; i <= n1; ++i){
      for(int j = 1; j <= n2; ++j){
	isPart[i][j] = (s1[i-1]==s3[i+j-1] && isPart[i-1][j]) || (s2[j-1]==s3[i+j-1]&& isPart[i][j-1]);
      }
    }
    return isPart[n1][n2];
  }
};

int main(){
  Solution s;
  //***********Interleaving string*********************
  string ss1= "aabcc";
  //string ss2="dbbca";
  string ss2 ="";
  string ss3="aadbbcbcac";
  string ss4="aadbbbaccc";
  string ss5 ="aabcc";
  bool isPart =   s.isInterleavingString(ss1,ss2,ss3);
  bool isPart2 = s.isInterleavingString(ss1,ss2,ss5);
  cout << isPart << " " << isPart2 << endl;
  getchar();
  return 0;
}
