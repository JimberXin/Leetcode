#include<iostream>
#include<vector>
using namespace std;


//*********************************Edit Distance****************************
// Given two words word1 and word2, find the minimum number of steps required
//to convert word1 to word2. 
 //(each operation is counted as 1 step.)
//You have the following 3 operations permitted on a word:
//a) Insert a character
//b) Delete a character
//c) Replace a character
 //*  D[i,j]: the minimal edit distance for the i numbers of s1 and j numbers of s2
 //1. d[0, j] = j;
// 2. d[i, 0] = i;
// 3. d[i, j] = d[i-1, j - 1] if A[i] == B[j]
// 4. d[i, j] = min(d[i-1, j - 1],    substitue
//                  d[i, j - 1],         insert
//                  d[i-1, j] ) + 1  if A[i] != B[j]   delete

class Solution{
  int minEditDistance(string word1, string word2){
    int n1 = word1.length();
    int n2 = word2.length();
    vector<vector<int> > dp(n1+1, vector<int>(n2+1,0));
    for(int i =0 ; i <= n1;  ++i)
      dp[i][0] = i;
    for(int j=0; j <= n2; ++j)
      dp[0][j] = j;
    for(int i = 1; i <= n1; ++i){
      for(int j =1; j <= n2; ++j){
	if(word1[i-1] == word2[j-1])
	  dp[i][j] = dp[i-1][j-1];
	else
	  dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] ) +1;
      }
    }
    return dp[n1][n2];
  }
}

//**************Edit Distance**********************
int main(){
  Solution s;
  string word1 ="hollo";
  string word2 ="helk";
  int minDistance = s.minEditDistance(word1,word2);
  cout << minDistance << endl;
  
  getchar();
  return 0;
}
