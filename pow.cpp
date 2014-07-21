#include<iostream>


using namespace std;

class Solution {
public:
    double pow(double x, int n)
	{
           if(x==0)
			   return n;
		   if(n==0 || x == 1)
			   return 1.0;
		   

		   double result = 1.0;
		   if(n>0)
			   for(int i = 0; i< n;i++)
			   {
				    result *= x;
					if( result  < 0.000000000000000001)
						return 0.0;


			   }
		   else if(n<0)
		   {
			      n  *= -1;
				  for(int i=0; i< n; i++)
				  {
					  result *= x;
					  if (abs(result) < 0.00000000000000001)
						   return 0.0;
				  }
				  result = 1.0/result;			     
		   }
			   return result;      
    }
};
int main()
{
	Solution s;
	double result = s.pow(0.000001, 1412123);
	cout << result << endl;

	getchar();
	return 0;
}