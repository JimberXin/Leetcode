#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Given a string S and a string T, find the minimum window in S which will contain 
//all the characters in T in complexity O(n).    For example,
//S = "ADOBECODEBANC",   T = "ABC"   ========>    Minimum window is "BANC".
//If there is no such window in S that covers all characters in T, return the emtpy string "".
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

//Solution: using two pointers left and right, maintain the area that [left, right] has the same number of characters as T
class Solution {
public:
    string minWindow(string S, string T) {
		int n1 = S.length();
		int n2 = T.length();
		string result;
		if(n1 == 0 || n2 == 0) 
			return result;
		int counts[256], now[256];  // now records
		memset(counts, 0, sizeof(counts));
		memset(now, 0, sizeof(now));
		for(int i = 0; i < n2; ++i)
			counts[ T[i] ]++;
		int left, right, begin, end;  // left and right is two points. begin and end records the index result
		int num = 0, minLen = INT_MAX;  //num is the numbers of characters between left and right
		for(left = 0, right = 0; right < n1; ++ right){
			//the num of characters are not enough
			if(num < n2)
			{
			    if( now[ S[right] ] < counts[ S[right] ])
		             ++ num;
			     ++now[ S[right] ];
		     }
			if( num == n2)
			{
				//update the left pointers, while still keep num==n2
				 while( left <= right && now[ S[left] ] > counts[ S[left] ])
				 {
					   --now[ S[left] ];  //
					   ++left;
				 }
				 //update the current min length
				 if( minLen > right - left + 1){
					  minLen = right - left + 1;
					  begin = left;
					  end = right;
				 }
				 // move the left pointers until num is less than n2
				 while( left <= right && num == n2)
				 {
					    --now[ S[left] ] ;
						if( now[ S[left] ] < counts[ S[left] ])
							-- num;
						++left;
				 }
			}
		}//end for left
		if(minLen == INT_MAX)
			return "";
		return   S.substr(begin, minLen);
    }
};

int main(void){
	Solution s;
	string S = "babb";
	string T = "baba";
	string res = s.minWindow(S,T);
 	cout << res << endl;
	getchar();
	return 0;
}

	