#include< iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n)
    {
        //       
       /* if (A == NULL) return 0;
        int t;
         int *x= new int[k];
          x[0] = ~0;
		  for(int i = 1;i<k;i++)
			  x[i] = 0;
        for (int i = 0; i < n; i++) 
		{
            t = x[k-1];
            for (int j = k-1; j > 0; j--) {
                x[j] = (x[j-1] & A[i]) | (x[j] & ~A[i]);
            }
            x[0] = (t & A[i]) | (x[0] & ~A[i]);
        }
        return x[l];*/

		if( NULL == A)
			 return 0;
		int *x = new int[3];
		 x[0] = ~0;  x[1] = 0; x[2] = 0;
		 for(int i=0;i<n;i++)
		 {
			   int t = x[2];
			   x[2] = (x[1] & A[i]) | ( x[2] & ~A[i]);
			   x[1] = (x[0] & A[i]) | ( x[1] & ~A[i]);
			   x[0] = (  t    & A[i]) | ( x[0] & ~A[i]);
		 }
        //
        return x[1];
    }
};

int main()
{
	  Solution s;
	  int arr[] = {2,2,2,19,32,19,32,19,104,32};
	  int result = s.singleNumber(arr,sizeof(arr)/sizeof(int));
	  cout << result << endl;
	  getchar();
	  return 0;
}