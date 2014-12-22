//Last Modified:  2014/12/22
//Author:  Junbo Xin

/*
*******************************Problem Description******************************************
Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer.
 If you still see your function signature returns a char * or String,
 please click the reload button  to reset your code definition.
*/

#include<iostream>

using namespace std;
class Solution {
public:
  char *strStr(char *haystack, char *needle){
    if(NULL == haystack || NULL == needle)
      return NULL;
    char *p1,*p2;
    p1 = haystack;
    p2 = needle;   //p2 should always remains the same
    while(*haystack != '\0' && *needle != '\0'){
      if(*haystack++ != *needle++){
	needle = p2;  //needle reset to the begin;
	haystack = ++p1; // haystack  points to the next one
      }
    }
    if(*needle == '\0')
      return p1;		  
    return NULL;
  }
};

int main(){
  char* s1 = "334sacsld3";
  char* s2 = "sacs3";
  Solution s;
  char* result = s.strStr (s1,s2);
  if(result == NULL )
    cout << "NULL "<< endl;
  else
    cout << result << endl;
  getchar();
  return 0;
}
