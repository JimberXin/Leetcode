#include<iostream>
using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) 
    {
        //
          int low = 0;
		  int high = n -1;
		  while(high >= low)
		  {
			  int mid = (low + high)/2;
			  if( target ==  A[mid])
				  return mid;
			  if( target > A[mid])
				   low = mid +1;
			  else
				  high = mid -1;
		  }
		  return low; 
        
        
        //
    }
};

int main(void)
{
	int arr[] = {6};
	Solution s;
	int index = s.searchInsert (arr,sizeof(arr)/sizeof(int),10);
	cout << index << endl;
	  getchar();
	  return 0;
}