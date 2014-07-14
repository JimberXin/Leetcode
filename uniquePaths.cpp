#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        //
         /* if(m == 0 || n== 0)
			  return (m == 0 && n ==0)? 0:1;
		  return	  (uniquePaths(m-1,n)+uniquePaths(m,n-1));*/
		 int  counts = (m > n)? n-1:m-1;
		 int up = m+n-2;
		 int down = 1;
		 int denomitor = 1;
		 int numerator = 1;
		 double result =1;
		 //  up may be overflowed
		 //  from top to bottom may have lost
		 while(down != counts+1)
		 {
			//numerator *= up--;
			//denomitor *= down --;
			result *=  (double)up--/down++;
		 }
		     return (int)result;

        //
    }
};

int main()
{
	Solution s;
	int num = s.uniquePaths(4,11);
	cout << num << endl;
	getchar();
	return 0;
}