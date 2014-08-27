#include<iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) 
    {
        //
		   if(n == 0)
			   return -1;
		   if(n == 1)
			   return target == A[0]?0:-1;
           int low = 0;
		   int high = n-1;
		   while(low <= high)
		   {
			     int   mid = low+ (high-low)/2;
				 if(A[mid] == target)
					 return mid;
				 //*********************1st case**********************
				 if(A[mid] < target)
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
		   return -1;
        //
    }
};


int main(void)
{

	Solution s;
	int arr[] = {4,5,6,7,8,0,1,2,3,4};
	int result = s.search(arr,sizeof(arr)/sizeof(int),7);
	cout << result  << endl;
	getchar();
	return 0;
}