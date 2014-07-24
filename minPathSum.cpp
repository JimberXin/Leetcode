#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) 
    {
        //Using the DP:  f[i][j] = min( f[i-1][j], f[i][j-1]) + grid[i][j]
           int m = grid.size();
		   int n = grid[0].size();
		   vector<vector<int> > f(m,vector<int>(n));
		   int i,j;
		   f[0][0] = grid[0][0];
		   for(i = 1; i < n; i++)
			   f[0][i] = f[0][i-1] + grid[0][i];
		   for(j = 1; j < m;  j++)
			   f[j][0] = f[j-1][0] + grid[j][0];

		   for(i = 1; i <  m;  i++)
			     for( j = 1; j <  n;  j++)
					 f[i][j] = min( f[i-1][j], f[i][j-1]) + grid[i][j];
        
            return f[m-1][n-1];
        
        
        //
        
    }
};


int main()
{
	Solution s;
	int arr[3][3] ={ {1,2,3},{3,4,5},{6,7,8}};
	vector<vector<int> > v;
	vector<int> line;
	for(int i = 0;  i < sizeof(arr)/sizeof(arr[0]);  i++)
	{
		for(int j = 0; j < sizeof(arr[0])/sizeof(int);  j++)
			line.push_back(arr[i][j]);
		v.push_back(line);
		line.clear();
	}

	int result = s.minPathSum(v);
	 cout<< result << endl;
	getchar();
	return 0;

}