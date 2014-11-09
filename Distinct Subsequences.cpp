#include<iostream>
#include<vector>
#include<string>
using namespace std;


/*
Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none)
of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).   Here is an example:
S = "rabbbit", T = "rabbit"      Return 3.
*/

//define:   table[i][j] : S[0..i-1] has table[i][j] subsequences T[0..j-1]
//S[i-1] == T[j-1],   table[i][j] = table[i-1][j-1] + table[i-1][j]£»
//S[i-1] != T[j-1],    table[i][j] = table[i-1][j]

class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.length();
		int n =  T.length();
		vector<vector<int> > table(m+1, vector<int>(n+1, 0));
		for(int i = 0; i <= m; ++i)
			table[i][0] = 1;  

		for(int i = 1; i <= m; ++i)
		{
			for(int j = 1;  j <= i && j <= n; ++j)
			{
				if(S[i-1] == T[j-1])
					table[i][j] = table[i-1][j-1] + table[i-1][j];
				else
					table[i][j] = table[i-1][j];
			}
		}
		return table[m][n];
	}
};

int main(){
	Solution s;
	string S = "rabbbit";
	string T = "rabbit";
	int num = s.numDistinct(S,T);
	cout << num << endl;
	getchar();
	return 0;
}