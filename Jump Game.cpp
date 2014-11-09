#include<iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
          int max = 0;
		  for(int i=0; i < n && i <= max; i++)
			  max = A[i] + i > max ? A[i]+i: max;
		  return max >= n-1;
    }
};

int main(void){
	Solution s;
	int arr[] = {2,3,1,1,4};
	bool isTrue = s.canJump(arr,sizeof(arr)/sizeof(int));
	getchar();
	return 0;
}