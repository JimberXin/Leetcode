#include<iostream>
using namespace std;

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    if(NULL == A || n == 0)
      return 1;
    int pos = 0;
    //***the ith postion puts i+1****
    while(pos < n){
      if(A[pos]>0 && A[pos]-1<n && A[pos]!=pos +1 && A[pos]!=A[A[pos]-1])
	swap(A[pos],A[A[pos]-1]);
      else
	pos++;
    }
    for(int i=0; i<n; i++){
      if(A[i] != i+1)
	return i+1; 
    }	
    return n+1;
  }
  void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
  }
};

int main(void){
  Solution s;
  int arr[] = {2,3,5,0,1,-3};
  int missInt = s.firstMissingPositive(arr,sizeof(arr)/sizeof(int));
  cout << missInt << endl;
  getchar();
  return 0;
}
