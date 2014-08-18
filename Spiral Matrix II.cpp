#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > result(n,vector<int>(n) );
		//*******0, 1,2,3,...(i-1)tatal levl: 4*i*(n-i)
		for(int level = 0; level < n /2; level++){
			   
			   for(int i = level; i < n - level - 1; i++)
				     result[level][i] = 4*level*(n-level) + i+1-level;

			   for(int i = level; i < n - level-1; i++)
				     result[i][n-level-1] = 4*level*(n-level) + n+i - 3*level;

			   for(int i = n-level-1; i > level; i--)
				     result[n-level-1][i] = 4*level*(n-level)+3*n-i-5*level-2;

			   for(int i = n-level-1; i > level; i--)
				     result[i][level] = 4*level*(n-level)+4*n -i- 7*level -3;
		}
		if( n%2)
			 result[(n-1)/2][(n-1)/2] = n*n;
		return result;       
    }
};

int main(void){
	Solution s;
	vector<vector<int> > res = s.generateMatrix(19);
	getchar();
	return 0; 
}