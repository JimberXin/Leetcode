#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target)
  {
    // Giving a  m * n matrix 
    vector<vector<int> > result;
    vector<int> line;
    int m = matrix.size();
    int n = matrix[0].size();
    // find the low that the target located
    int line_low = 0;
    int line_high = m-1;
    while( line_high >= line_low)
      {
	int line_mid = (line_low + line_high )/2;
	if( *matrix[line_mid].begin() == target)
	  return true;
	else if(*matrix[line_mid].begin() > target)
	  line_high = line_mid-1;
	else
	  line_low = line_mid+1;
      }
    //***the target located in line_high(except for line_high = -1)***
    int col_low = 0;
    int col_high = n-1;
    if(line_high == -1)
      line_high = 0;
    while( col_high >= col_low)
      {
	int col_mid = (col_low + col_high)/2;
	if( matrix[line_high][col_mid] == target)
	  return true;
	else if(matrix[line_high][col_mid] > target)
	  col_high = col_mid -1;
	else
	  col_low = col_mid +1;
      }
    return false;
    //    
  }
};

int main(void)
{
  Solution s;
  vector<vector<int> >  mat;
  vector<int> line;
  //int arr[][4] = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
  int arr[][1] = {{1}};
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
      for(int j=0;j<sizeof(arr[0])/sizeof(int);j++)
	line.push_back (arr[i][j]);
      mat.push_back(line);
      line.clear();
    }

  //cout  << mat.size() << endl;
  //cout << mat[0].size() << endl;
  for(vector<vector<int> > ::iterator outside = mat.begin();outside != mat.end(); outside++)
    {
      for(vector<int>::iterator inside = outside->begin(); inside != outside->end(); inside++)
	cout << * inside << " " ;
      cout << endl;
    }

  bool isFind = s.searchMatrix(mat,0);
  cout << "Whether the value 3 is found: " << isFind << endl;
  getchar();
  return 0;
}
