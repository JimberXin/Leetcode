#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
         int*d = new int[n+1];
		 d[1] = 1;
		 d[2] = 2;
		 for(int i = 3; i < n+1; i++)
			 d[i] = d[i-1] + d[i-2];
		 return d[n];
    }
};

int main(void){
	Solution s;
	int number = s.climbStairs(5);
	cout << number << endl;
	getchar();
	return 0;
}