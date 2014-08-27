#include<iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
          if(n==0) return false;
		  int low = 0;
		  int high = n-1;
		  while(low <= high)
		  {
			    int mid = low + (high - low)/2;
				if( target == A[mid])
					return true;
                 if(A[low] == A[mid] && A[mid] == A[high])
				 {
					     ++ low;
						 --high;
				 }
			 //*********************1st case**********************
				 else if(A[mid] < target)
				 {
					     if(A[mid] <A[low])   //mid is  in  the second half
						 {
							   if(target <  A[low]) //target is in the second half
								   low = mid+1;
							   else
								   high = mid -1;
						 }
						 else	                              // mid is in the first half
							       low = mid + 1;
				 }
				 //***********************2nd case**************************
				 else
				 {
					       if(A[mid] >=A[low])   //mid is in the first half
						   {
							     if(target >= A[low])  // target is in the first half
									 high = mid -1;
								 else 
									 low = mid +1;
						   }
						   else                              // mid is in the second half
							       high = mid -1 ;
				 }
		   } 
		  return false;
    }
};

int main(void)
{
	Solution s;
	int arr[] = {1,1,2,1,1,1,1,1,1,1,1,1};
	bool result = s.search(arr,sizeof(arr)/sizeof(int),2);
	cout << result  << endl;
	getchar();
	return 0;
}

