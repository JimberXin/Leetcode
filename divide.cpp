#include<iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        // using long long to avoid overflow
		  int flag=(  (dividend<=0 && divisor <0) || (dividend>=0 && divisor >0) )? 1:-1;
		  unsigned long long dividendTemp = abs((long long)dividend);
		  unsigned long long divisorTemp = abs((long long)divisor);
		  return flag*divideHelper(dividendTemp, divisorTemp);
        
        //
        
    }

	long long divideHelper(long long big, long long small)
	{
		   if( big < small)
			   return 0;
		   
		   long long  result = 1;
		   long long temp = small;
		   long long left;
		   while( temp <= big)
		   {
			       left =  big - temp;
				   temp <<= 1;
				   if(temp > big)
					   break;
				   else
					   result <<= 1;
		   }
		   return result + divideHelper(left,small);
	}
};

int main(void)
{
	Solution s;
	int a = 2147483647;
	int b= 1;
	int result = s.divide(a,b);
	cout << a/b << endl;
	cout << result << endl;
	getchar();
	return 0;
}