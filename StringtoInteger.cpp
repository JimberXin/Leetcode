#include<iostream>
using namespace std;
class Solution {
public:
    int atoi(const char *str)
    {
        //
		          long long result = 0;	
			      while(*str == ' ')
					  str++;
				  if(*str == '\0' || *str != '+' && *str != '-' && *str < '0' && *str >'9')
					  return 0;
                   int flag = 1;
				   if(*str == '-')
				   {
					   flag = -1;
					   str++;
				   }
				   else if(*str == '+')
					   str++;
				   //first unsigned character
				   if(*str < '0' || *str > '9')
					   return 0;
				   else
					   //***********main case to deal with the convention**********
					   while(*str != '\0')
				      {
					        if (*str < '0' || *str > '9') 
								return flag *result;
							result = 10*result + (*str - '0');	
							str++;
							if(abs(result) > INT_MAX)
								return flag>0? INT_MAX:INT_MIN;
				      }
		                return flag *result;
		//
    }
};

int main(void)
{
	 Solution s;
	char* str = "  -0012a42";
	 int result = s.atoi(str);
	 cout << result << endl;
	 getchar();
	 return 0;
}