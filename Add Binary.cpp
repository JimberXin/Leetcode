#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	char addChar(char a, char b, char &c){
		   char res;
		   if(a == '0' && b == '0'){
			      res = c;
				  c = '0';
		   } else if( a == '1' && b == '1'){
			      res = c;
				   c = '1';
		   } else {
			      res = c=='1'? '0': '1';
		   }
		        return res;
	}
    string addBinary(string a, string b) {
          string result =  a.size() > b.size()? '1'+a: '1'+b;
		  string::iterator pc = result.begin() + result.size() -1;
		  char carry = '0';
		  const char* pa = a.data() + a.size()  -1;
		  const char* pb = b.data() + b.size() -1;

		  while( pa != a.data() -1 || pb != b.data() -1 ) {
			     if( pa == a.data() -1)
					 *pc-- = addChar('0',*pb--,carry);
				 else if(pb == b.data() -1)
					 *pc-- = addChar(*pa--,'0',carry);
				 else
					 *pc-- = addChar(*pa--, *pb--, carry);
    }
		  if(carry == '0')
			   result.erase(result.begin());
		  return  result; 
	}
};

int main(void){
	Solution s;
	string str1 = "11111";
	string str2 = "1";
	string res = s.addBinary(str1,str2);
	//cout << res << endl;
	getchar();
	return 0;
}