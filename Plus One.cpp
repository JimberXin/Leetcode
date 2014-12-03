#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int>::size_type n = digits.size();
    if(digits.empty())
      return digits;
    int i = n-1; 
    while( i>=0 && digits[i] == 9)
      digits[i--] = 0;
    if(i != -1)
      digits[i] += 1;
    else
      digits.insert(digits.begin(),1);
    return digits;
  }
};

int main(void){
  Solution s;
  int arr[] ={ 9,3,5,7};
  vector<int> num;
  for(int i =0; i< sizeof(arr)/sizeof(int); i++)
    num.push_back(arr[i]);
  vector<int> res = s.plusOne(num);
  getchar();
  return 0;
}
