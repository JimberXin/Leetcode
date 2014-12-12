#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
  {
    //
    int m = obstacleGrid.size();
    int n= obstacleGrid[0].size();
    vector<vector<int> > val(m,vector<int>(n) );
    val[0][0] = obstacleGrid[0][0] == 1 ? 0:1;

    for(int i=1;i<m;i++)
      val[i][0] = obstacleGrid[i][0] == 1? 0: val[i-1][0];

    for(int j=1; j<n; j++)
      val[0][j] = obstacleGrid[0][j] == 1? 0: val[0][j-1];

    for(int i=1; i<m; i++)
      for(int j=1; j<n ; j++)
	val[i][j] = obstacleGrid[i][j] == 1? 0: val[i][j-1] + val[i-1][j];

    return val[m-1][n-1];      
    //
        
  }
};

int main(void)
{
  Solution s;
  vector<vector<int> > G;
  vector<int>  line;
  //int array[3][3] = { {0,0,0},{0,1,0},{0,0,0} };
  int array[20][1] = {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
  for(int i=0;i<20;i++)
    {
      for(int j=0; j<1;j++)
	line.push_back(array[i][j]);
      G.push_back(line);
      line.clear();
    }
	
  int num =  s.uniquePathsWithObstacles(G);
  cout << num <<  endl;
  getchar();
  return 0;
}
