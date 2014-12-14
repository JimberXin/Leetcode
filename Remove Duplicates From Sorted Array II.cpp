#include<iostream>
using namespace std;

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if(n == 0 || n == 1)
      return n;
    int start = 1; 
    int first,second;
    first = 0;
    second = 1;
    for(int i=2; i< n; i++)
      {
	if(A[first] != A[i] )
	  {
	    A[start++] =  A[second];
	    first = second;
	    second = i;
	  }
      }
    A[start++] = A[second];
    return start;
  }
};

int main(void) {
  Solution s;
  int arr[] ={1,2,2,2,2,3,3,4,5,6,7,7,7,8};
  int result = s.removeDuplicates(arr,sizeof(arr)/sizeof(int));
  cout << result << endl;
  getchar();
  return 0;
}
