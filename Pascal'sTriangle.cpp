#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    vector<int> line;
    queue<int> q;
    int i = 1;
    q.push(i);
    for( i =0; i < numRows;  i++) {
      int s = 0;
      q.push(s);
      for(int j=0; j < i+2; j++) {
	int t = q.front();
	q.pop();
	int temp = s + t;
	q.push(temp);
	s = t;
	if( j != i+1)
	  line.push_back(s);
      }
      result.push_back(line);
      line.clear();
    }
    return result;       
  }
};

int main(void)
{
  Solution s;
  vector<vector<int> > res = s.generate(11);
  getchar();
  return 0;
}
