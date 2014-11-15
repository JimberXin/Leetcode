#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

//Given a 2D binary matrix filled with 0's and 1's, 
//find the largest rectangle containing all ones and return its area.
//      0  1  1  0  1           0   1   1   0   1            2
//      1  1  0  1  0           1   2   0   1   0            2
//      0  1  1  1  0   ==> 0   3   1   2   0   ==> 3
//      1  1  1  1  0           1   4   2   3   0            6
//      1  1  1  1  1           2   5   3   4   1            9

//http://www.tuicool.com/articles/6vmyyi

class Solution {
public:
	int maxRectangle(vector<int> height){
		stack<int> stk;
		height.push_back(0); //dummy element, to end the calculation
		int i = 0, maxAera = 0;
		while(i < height.size() )
		{
			  if( stk.empty() || height[ stk.top() ] <= height[i] )
				  stk.push(i++);
			  else{
				  int temp = stk.top();
				  stk.pop();
				  maxAera = max(maxAera, height[temp] * (stk.empty()? i: i - stk.top() - 1) );
			  }
		}
		return maxAera;
	}

	// turn into the Problem: Largest Rectangle in Histogram(2,1,5,6,2,3)
	//https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
	//Find every line's maximal rectangle, each line be the bottom of the rectangle
    int maximalRectangle(vector<vector<char> > &matrix) {
		int m = matrix.size();
		if(m == 0) return 0;
		int n = matrix[0].size();
		vector<int> height(n,0);
		int result = 0;
		for(int i = 0; i < m; ++i){
			 for(int j = 0; j < n; ++j){
				  height[j] = matrix[i][j] == '0' ? 0: height[j]+1;
			 }
			 result = max(result, maxRectangle(height));
		}
		return result;
    }
};

int main(){
	Solution s;
	char arr[5][5] ={ {'0', '1', '1', '0', '1'}, 
	                             {'1', '1', '0', '1', '0'},
	                             {'0', '1', '1', '1', '0'}, 
	                             {'1', '1', '1', '1', '0'}, 
	                             {'1', '1', '1', '1', '0'}  };
	vector<char> line;
	vector<vector<char> >table;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j)
			line.push_back(arr[i][j]);
		table.push_back(line);
		line.clear();
	}
	int result = s.maximalRectangle(table);
	cout << result << endl;
	getchar();
	return 0;
}