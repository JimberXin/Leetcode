#include<iostream>
using namespace std;

//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.
class Solution {
public:
    int maxProduct(int A[], int n) {
      int maxRes = A[0];  //records the current position max product, shoule include A[i]
      int minRes = A[0];  //records the current position min product, should include A[i]
      int result = A[0];    // recodrds the final result
      for(int i = 1; i < n; ++i){
	if(A[i]  < 0){
	  int temp = maxRes;
	  maxRes = minRes;
	  minRes = temp;
	}
	maxRes = max(maxRes*A[i], A[i]);
	minRes = min(minRes*A[i], A[i]);
	result = max(result, maxRes);
      }
      return result;
    }
};

int main(){
  Solution s;
  int arr[] ={2, -3,-2,-2, -3,0,8,5};
  int res = s.maxProduct(arr, sizeof(arr)/sizeof(int));
  cout << res << endl;
  getchar();
  return 0;
}
