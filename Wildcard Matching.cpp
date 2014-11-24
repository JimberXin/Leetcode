#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Implement wildcard pattern matching with support for '?' and '*'.
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//The matching should cover the entire input string (not partial).
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
// examples:
//isMatch("aa","a") ¡ú false
//isMatch("aa","aa") ¡ú true
//isMatch("aaa","aa") ¡ú false
//isMatch("aa", "*") ¡ú true
//isMatch("aa", "a*") ¡ú true
//isMatch("ab", "?*") ¡ú true
//isMatch("aab", "c*a*b") ¡ú false

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		/*
        const char* prevS =  NULL;
		const char* prevP =  NULL;
		bool start = false;
		while( *s != '\0')
		{
			  if(*p == '?'){
				   ++s;
				   ++p;
			  } else if ( *p == '*'){
				   prevP = ++p;
				   prevS = s;
				   start = true;
			  } else  { // *p is not '?' nor '*'
				    if(*p == *s){
						++s;
						++p;
					} else if(start){  //found *p != *s, traceback
						 p = prevP;
						 s = ++ prevS;
					}else   return false;
			  }
		}// end for while
		while(*p == '*') ++p;
		return  (*p=='\0');
		*/ 
		const char* star=NULL;
        const char* ss=s;
        while (*s){
            //match, only in two cases,  adancing both pointers.
            if ( (*p=='?') || (*p==*s) ) { s++; p++; continue;} 

            // * found in pattern p, track index of *, records the current position
            if (*p=='*'){ star=p++;  ss=s; continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if ( star != '\0' ){ p = star+1;  s=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }
       //check for remaining characters in pattern
        while (*p=='*') p++;
        return (*p == '\0');  
    }
};

int main(){
	Solution solu;
	const char* t = "c*ab*c";
	const char* s= "cddabbac";
	bool result = solu.isMatch(s,t);
	cout << result << endl;
	getchar();
	return 0;
}