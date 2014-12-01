#include<iostream>

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) 
  {
    int i=0;
    for(i=1;i<n;i++)
      A[0] ^= A[i];
    return A[0];
  }
};

int main(void)
{
  int T[] = {2,2,3,3,5,5,212,6,1,6,1};
  int length = sizeof(T)/sizeof(int);
  Solution s;
  int number = s.singleNumber(T,length);
  cout <<" length of the array is : " <<  length <<  endl;
  cout << "The single number is: " <<  number << endl;
  getchar();
  return 0;
}
