//Last Modeified: 12/14/2014
//Author: Junbo Xin

#include<iostream>
#include<vector>
using namespace std;

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0.
Do it in place.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
  //**Time Complexity: O(mn);  Space Complexity:O(1)****
  void setZeroes(vector<vector<int> > &matrix) {
    bool firstRow = false;
    bool firstCol = false;
    int m = matrix.size();
    if( m == 0)
      return;
    int n = matrix[0].size();
    if(n == 0)
      return;
    
    for(int i = 0;  i < m;  i++)
      if( 0 == matrix[i][0] )
	firstCol = true;
    
    for(int j = 0;  j < n;  j++)
      if (0 == matrix[0][j])
	firstRow = true;
    
    for(int i=0; i < m; i++) {
      for(int j = 0;  j < n;  j++) {
	if( 0 == matrix[i][j] ){
	  matrix[i][0] = 0;
	  matrix[0][j] = 0;
	}
      }
    }
    //************set the row to be 0****************
    for(int i = 1; i < m; i++){
      if( 0 == matrix[i][0] ){
	for(int j = 1; j < n; j++){
	  matrix[i][j] = 0;
	}
      }
    }
    //***********set the col to be 0*****************
    for(int j = 1; j < n; j++) {
      if( 0 == matrix[0][j] ){
	for(int i = 1;  i < m; i++){
	  matrix[i][j] = 0;
	}
      }
    }
    
    if(firstRow){
      for(int i = 0; i < n; i++)
	matrix[0][i] = 0;
    }
    
    if(firstCol){
      for(int i = 0; i < m; i++)
	matrix[i][0] = 0;
    }
    
  }
};

int main(void)
{
  Solution s;
  int arr[1][4]= { {1,2,4,0}};
  vector<vector<int> > res;
  vector<int> line;
  for(int i=0; i< sizeof(arr)/sizeof(arr[0]);i++){
    for(int j=0; j<sizeof(arr[0])/sizeof(int);j++){
      line.push_back(arr[i][j]);
    }
    res.push_back(line);
    line.clear();
  }
  
  s.setZeroes(res);
  getchar();
  return 0;
}
