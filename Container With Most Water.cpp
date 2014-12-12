#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int m= height.size();
    if( m ==0 || m == 1)
      return 0;
    int maxA = 0;
    int i = 0, j = m -1;
    while(i < j){
      if(height[i] < height[j]){
	  maxA =   max( maxA, height[i]*(j-i) );
	  i++;
      } else {
	maxA = max( maxA, height[j]*(j-i) );
	j--;
      }		     
    }
    return maxA;
  }
};

int main(void)
{
  Solution s;
  int arr[] = {8,3,5,6,4,7};
  vector<int> numbers;
  for(int i=0; i< sizeof(arr)/sizeof(int); i++)
    numbers.push_back(arr[i]);
  int result = s.maxArea(numbers);
  cout << result << endl;
  getchar();
  return 0;
}
