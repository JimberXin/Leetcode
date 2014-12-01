#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    vector<vector<bool> > rows(9, vector<bool>(9,false) ); 
    vector<vector<bool> > cols(9, vector<bool>(9, false) );
    vector<vector<bool> > block(9, vector<bool>(9, false) );
    for(int i = 0; i < 9; ++i){
      for(int j = 0; j < 9; ++j){
	if(board[i][j] == '.') continue;
	int num = board[i][j] - '1';
	if( rows[i][num] ||  cols[j][num] ||  block[i-i%3+j/3][num])
	  return false;
	else
	  rows[i][num] = cols[j][num] = block[i-i%3+j/3][num] = true;		  
      }
    }
    return true;
  }
};

int main(){
  Solution s;
  string arr[9] ={  "53..7....",
		    "6..195...",
		    ".98....6.",
		    "8...6...1",
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
  bool res = s.isValidSudoku(board);
  cout << res << endl;
  getchar();
  return 0;
}
