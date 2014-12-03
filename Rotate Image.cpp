#include<iostream>
#include<vector>
using namespace std;


// 1   2   3   4   5         25   20   15   10   5      21    16   11    6    1         
// 6   7   8   9  10         24   19   14   9    4      22    17   12    7    2 
//11  12  13  14  15  ===>   23   18   13  16    3 ==>  23    18   13   16    3  
//16  17  18  19  20         22   17   12   7    2      24    19   14    9    4
//21  22  23  24  25         21   16   11   6    1      25    20   15   10    5
class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    if(matrix.empty()) return;
    int n = matrix.size();
    //swap along the vice-dinanol
    for(int i = 0; i < n ;++i){
      for(int j = 0 ; j < n -i; ++j){
	int temp = matrix[i][j];
	matrix[i][j] = matrix[n-1-j][n-i-1];
	matrix[n-1-j][n-1-i] = temp;
      }
    }
    //swap along the center horizinal line
    for(int i = 0; i < n/2; ++i){
      for(int j = 0; j < n; ++j){
	int temp = matrix[i][j];
	matrix[i][j] = matrix[n-1-i][j];
	matrix[n-1-i][j] = temp;
      }
    }
  }
};

int main(){
  Solution s;
  int arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  vector<vector<int> > input;
  vector<int> line;
  for(int i = 0; i < 4; ++i){
    for(int j =0; j < 4; ++j)
      line.push_back(arr[i][j]);
    input.push_back(line);
    line.clear();
  }
  s.rotate(input);
  for(int i = 0; i< input.size(); ++i){
    for(int j = 0; j < input[i].size(); ++j)
      cout << input[i][j] << " ";
    cout << endl;
  }
  getchar();
  return 0;
}
