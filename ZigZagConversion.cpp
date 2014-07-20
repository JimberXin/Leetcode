#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) 
    {
		   if(nRows ==1)
			   return s;
            vector<string>  all(nRows);
			string result;
			//    0     2(n-1)   4(n-1)   6(n-1)...
			//  n-1   3(n-1)   5(n-1)   7(n-1)...
			int down = 1;
			int rows = 0;
			for(size_t  i=0; i<s.length(); i++)
			{
				all[rows].push_back(s[i]);
				    if(down)
						rows = rows == nRows-1? rows-1:rows+1;
					else
						rows = rows == 0? rows+1:rows-1;

					down =( ( i/(nRows-1)) %2 == 1 ) ? 0:1;  //see if the flag is up or down	
			}
			for(int i=0; i<nRows;i++)
				result += all[i];
			return result;
    }
};


int main(void)
{
	Solution s;
	string str = "ABCDE";
	//string str2 ="PAYPALISHIRING";
	string result = s.convert(str,10);
	getchar();
	return 0;
}