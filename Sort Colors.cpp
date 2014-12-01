#include<iostream>
using namespace std;

class Solution {
public:
  void swap(int &a, int& b)
  {
    int temp = a;
    a = b;
    b  = temp;
  }
  
  void sortColors(int A[], int n) {
    int first = 0, second = n-1;
    int cur = first;
    while(cur <= second){
      if(A[cur] == 0){
	if(cur > first)
	  swap(A[cur], A[first++]);
	else{
	  first++;
	  cur++;
	}
      } else if(A[cur] == 2){
	if(cur < second)
	  swap(A[cur],A[second--]);
	else
	  return;
      } else
	cur++;
    }
  }
};

int main(void){
  Solution s;
  int arr[] = {1,2,0,2,2,1,1,0,2,1,1,1,1,1,1,1,1,1};
  s.sortColors(arr,sizeof(arr)/sizeof(int));
  getchar();
  return 0;
}
