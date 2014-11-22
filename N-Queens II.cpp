#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int C[100];
	int totalNum;

	int checkIfOK(int row, int col){
		int  OK = 1;
		for(int i = 0; i < row; i++){
			if( C[i] == col || row - i == col - C[i] || row - i == C[i] - col){
				OK = 0;
				break;
			}
		}
		return OK;
	}
	
	int search(int row, int n){
		if( row == n){
			totalNum++;
			return totalNum;
		}
		//***********Travesing every column********
		for(int i = 0; i < n; i++){
			int OK = checkIfOK(row, i);
			if(OK){
				   C[row] = i;
				   search(row+1, n);
			}
		}
		return totalNum;
	}

    int totalNQueens(int n) {
		totalNum = 0;
         return search(0,n);
    }
};

int main(void)
{
	Solution s;
	int num = s.totalNQueens(2);
	getchar();
	return 0;
}