#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool isValidSudo(vector<vector<char> >&board, int row, int col){
		//for the cols
		  for(int i = 0; i < 9; ++i)
			  if( i != row && board[i][col] == board[row][col])
				  return false;
		  //for the rows
		  for(int j = 0; j < 9; ++j)
			  if( j != col && board[row][j] == board[row][col])
				  return false;
		  //for the blocks
		  int x= row/3 * 3;
		  int y = col/3 * 3;
		  for(int i = x; i < x +3; ++i)
			  for(int  j = y;  j < y + 3; ++j)
				  if( i != row && j != col && board[i][j] == board[row][col])
					  return false;

		  return true;
	}
    bool solveSudokuHelper(vector<vector<char> > &board) {
          for(int i = 0; i < 9; ++i){
			  for(int j = 0; j < 9; ++j){
						 if(board[i][j] == '.')
						 {
							   for(int k = 1; k < 10; ++k)
							   {
								    board[i][j] = k + '0';
								    if(isValidSudo(board, i, j) && solveSudokuHelper(board))
									    return true;
								    else
									    board[i][j] = '.';
						         }
							   return false; // current position (i,j) cannot fill any digits.
					    } //end for if
			   }//end for j
	    }// end for i
		  return true;
    }

	void solveSudoku(vector<vector<char> > &board) {
        solveSudokuHelper(board);
    }
};

int main(){
Solution s;
	string arr[9] ={  "53..7....",
			                    "6..195...",
		                         ".98....6.",
								 "8...6...3",
								 "4..8.3..1",
								 "7...2...6",
								 ".6....28.",
								 "...419..5",
								 "....8..79" };
	vector<char> line;
	vector<vector<char> > board;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j)
			line.push_back(arr[i][j]);
		board.push_back(line);
		line.clear();
	}
	s.solveSudoku(board);
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j)
			cout << board[i][j] << " ";
	  cout << endl;
	}
	getchar();
	return 0;
}