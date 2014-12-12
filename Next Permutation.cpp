#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
  //Using the STL algorithm 'next_permutation'
  void nextPermutation(vector<int> &num){
    int length = num.size();
    if(length == 0 || length == 1) return;
    int i = length -2;
    //******find the first pair that num[i] >= num[i+1]
    while( i>=0 && num[i] >= num[i+1] )
      i--;
    //not till the begin of the vector
    //find the first element bigger than num[i]
    if(i>=0){
      int j = length -1;
      while(num[j] <= num[i])
	j--;
      swap(num[i], num[j]);				  
    }
    vector<int>::iterator begin = num.begin() + (i +1);
    reverse( begin,  num.end());			     
  }
};

int main(void)
{
  Solution s;
  int arr[] ={5,7,6,4,3,1};
  vector<int> numbers;
  for(int i=0; i<sizeof(arr)/sizeof(int); i++)
    numbers.push_back(arr[i]);
  s.nextPermutation(numbers);
  getchar();
  return 0;
}
