#include<iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int *dp = new int[n];
		if(n ==0 ) return INT_MIN;
		for(int i =0; i < n; i++)
			dp[i] = INT_MAX;
		dp[0] = 0;
		for(int i = 1; i < n; i++){
			  for(int j = 0 ; j < i; j++){
				    if(A[j] + j >= i){
						  if(dp[j] + 1 < dp[i])
						    {
							    dp[i] = dp[j] + 1;
								break;
						    }
					 }
			    }
		   }
		  return dp[n-1];
    }
};

int main(void){
	Solution s;
	int arr[] ={ 2,3,1,1,4};
	int res = s.jump(arr,sizeof(arr)/sizeof(int));
	getchar();
	return 0;
}