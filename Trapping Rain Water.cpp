#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int trap(int A[], int n) {
    if(n == 0) return 0;
    int left = 0, right = n - 1;
    int cur, result = 0;
    while(left < right)
      {
	if(A[left] < A[right])
	  {
	    cur = left + 1;
	    while(cur < right && A[cur] <=  A[left])
	      result += A[left] - A[cur++]；// A[cur] <= A[left] < A[right]
	    left = cur;
	  } 
	else
	  {
	    cur = right - 1;
	    while(cur > left && A[cur] <= A[right])
	      result += A[right] - A[cur--];//A[cur] <= A[right] <= A[left
	    right = cur;
	  }
      }  // end while
    return result;
  }
};

int main(){
  Solution s;
  int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  int res = s.trap(arr, sizeof(arr)/sizeof(int));
  cout << res << endl;
  getchar();
  return 0;
}
