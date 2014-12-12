#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
  int C[50];
  int checkIfOK(int row, int col) {
    int OK = 1;
    for(int i = 0; i < row; i++){
      if(C[i] == col || C[i] - col == row - i || C[i] - col == i - row){
	OK = 0;
	break;
      }
    }
    return OK;
  }
	
  void search(vector<vector<string> > &result ,  int row, int n){
    if( row == n ){
      string line;
      vector<string> singleRes;
      for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
	  if(C[i]  != j)
	    line.push_back('.');
	  else
	    line.push_back('Q');
	}
	singleRes.push_back(line);
	line.clear();
      }
      result.push_back(singleRes);
      return;
    }
    for(int j = 0; j < n; j++){
      int OK = checkIfOK(row, j);
      if(OK){
	C[row] = j;
	search(result, row+1, n);
	// singleRes.pop_back();
      }
    }
  }

  vector<vector<string> > solveNQueens(int n){
    vector<vector<string> >result;
    search(result, 0, n);
    return result;         
  }
};

int main(void)
{
  Solution s;
  vector<vector<string> >res;
  res = s.solveNQueens(5);
  getchar();
  return 0;
}
	
