#include<iostream>
#include<vector>
#include<string>
using namespace std;


//Validate if a given string is numeric.
//Some examples:
//"0" => true
//" 0.1 " => true
//"abc" => false
//"1 a" => false
//"2e10" => true
//Note: It is intended for the problem statement to be ambiguous. 
//You should gather all requirements up front before implementing one.

//Solution: https://oj.leetcode.com/discuss/9013/a-simple-solution-in-cpp
class Solution {
public:
    bool isNumber(const char *s) {
        int i = 0;
		while(s[i] ==' ') ++i;  // skip the previous space
		if(s[i] == '+' || s[i] == '-')  ++i; // skip the sign
		int digitNum = 0, pointNum = 0;
		for(;  (s[i] >= '0' && s[i] <= '9') || s[i] == '.';  ++i)
			 s[i] == '.' ? pointNum++: digitNum++; //counts the digits and the point
		if(pointNum > 1 || digitNum <1)
			return false;

		if(s[i] == 'e'){
			++i;
			if(s[i] == '+' || s[i] == '-') ++i; // skip the sign

			digitNum = 0;
			for(; s[i] >= '0' && s[i] <= '9';++i)
				digitNum++;  //count the digit after 'e'
			if(digitNum < 1)
				return false;
		}

		while(s[i] == ' ') ++i; // skip the remaining space
		return s[i] == '\0';
    }
};

int main(){
	Solution s;
	const char* s1 = "231.34e921";
	bool res = s.isNumber(s1);
	getchar();
	return 0;
}