#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int numTrees(int n) 
  {
    if(n < 2) 
      return n;
    vector<int> f(n+1,1);
    f[1] = 1;
    f[2] = 2;
    for(int i=3; i <= n;i++)
      {
	int sum = 0;
	for(int j=0; j < i; j++)
	  sum += f[j] * f[i-j-1];
	f[i] = sum;
      }
    return f[n];
  }
};

int main(void)
{
  Solution s;
  cout << s.numTrees(5) << endl;
  getchar();
  return 0;
}
