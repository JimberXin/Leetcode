#include<iostream>
#include<vector>
#include<string>
using namespace std;
//four directions
int dir[4][2] = { {-1, 0},  {1, 0}, {0, -1}, {0,1} };
class Solution {
public:	
  bool DFS(vector<vector<char> >&board, string &word, vector<vector<bool> > &isUsed, int x, int y, int index){
    if(index == word.length()) 
      return true;
    int m = board.size();
    int n = board[x].size();
    //search in the current index, for 4 directions, left, right, down, up
    for(int i = 0; i < 4; ++i){
      int newX = x + dir[i][0];
      int newY = y + dir[i][1];
      if(newX >=0 && newX < m && newY >= 0 && newY < n
	 && isUsed[newX][newY] == false && word[index] == board[newX][newY])
	{
	  isUsed[newX][newY] = true;
	  if( DFS(board, word, isUsed, newX, newY, index+1) )
	    return true;
	  isUsed[newX][newY] = false;
	}			
    }
    return false;
  } // end DFS()

  bool exist(vector<vector<char> > &board, string word) {
    if(word.empty()) return true;
    if( board.size() == 0 )  return false;
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool> > isUsed(m, vector<bool>(n, false));
    for( int i = 0; i < m; ++i){
      for(int j = 0; j < board[i].size(); ++j){
	if( board[i][j] == word[0]){
	  isUsed[i][j] = true;
	  if(DFS(board, word, isUsed, i, j, 1))
	    return true;
	  isUsed[i][j] = false;
	} 			 
      } // end for j
    } // end for i
    return false;
  }
};

int main(){
   Solution s;
   char *input[4]={"ABCE","SFCS","ADEE"};
   vector<vector<char> > board;
   vector<char> line;
   int n = sizeof(input)/sizeof(input[0]) - 1;
   for(int i = 0; i < n; ++i){
     for(int j =0; input[i][j] !='\0'; ++j)
       line.push_back(input[i][j]);
     board.push_back(line);
     line.clear();
   }
   bool find = s.exist(board, "SFCEF");
   getchar();
   return 0;
}
