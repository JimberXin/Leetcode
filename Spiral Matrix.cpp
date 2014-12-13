#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    int rowNum = matrix.size();
    if(rowNum == 0)
      return result;
    int colNum =  matrix[0].size();
    if(colNum == 0)
      return result;
    int minNum = min(rowNum, colNum);
    int  levelNum = minNum/2;
    //visit accoring to the level number, each has 4 edges: up, right, down, left
    for(int level =0; level < levelNum; level++)
      {
	for(int i = level;  i < colNum - level-1;   i++)
	  result.push_back ( matrix[level][i] );
	for(int i = level;  i < rowNum - level -1;  i++)
	  result.push_back ( matrix[i][colNum - level -1]);
	for(int i = colNum - level  - 1;   i > level;  i--)
	  result.push_back ( matrix[rowNum - level -1][i] );
	for(int i = rowNum - level - 1; i > level; i--)
	  result.push_back ( matrix[i][level] );
      }
    //*************deal with the case that minNum is an odd************
    if( minNum - 2*levelNum)
      {
	if(rowNum > colNum)
	  for(int i = levelNum;  i <  rowNum - levelNum;  i++)
	    result.push_back ( matrix[i][levelNum] );
	else
	  for(int i= levelNum;  i < colNum - levelNum ;  i++)
	    result.push_back (matrix[levelNum][i]);
      }
    return result;                 
  }
};

int main(void)
{
  Solution s;
  int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
  vector<vector<int> > numbers,numbers2;
  vector<int> line;
  for(int i=0; i< sizeof(arr)/sizeof(arr[0]);i++)
    {
      for(int j=0;j<sizeof(arr[0])/sizeof(int);j++)
	line.push_back(arr[i][j]);
      numbers.push_back(line);
      line.clear();
    }
  vector<int> res = s.spiralOrder(numbers2);
  getchar();
  return 0;
}
