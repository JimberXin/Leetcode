#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) 
    {
        //
           string result;
		   int F[10];
		   bool isVisted[10];
		   F[0] =1;
		   for(int i =1; i < 10; i++)
			   F[i] = F[i-1] * i;
		   memset(isVisted,0,sizeof(isVisted));
		   -- k;
		   for(int i = n-1; i >= 0; i--)
		   {
			      int temp = k/F[i];
				  int j =1;
 				  for( ; j < 10 ; j++)
				  {
  					     if( isVisted[j] == 0)
 							 temp --;
 						 if(temp < 0 )
							 break;
				  }
				  result += '0' + j;
				  k %= F[i];
				  isVisted[j] = 1;
		   }     

		   return result;
        //      
    }
};

int main(void)
{
     Solution s;
	 string str = s.getPermutation(7,30);
	 getchar();
	 return 0;
}