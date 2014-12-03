#include<iostream>
#include<map>
#include<vector>
using namespace std;

//1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//1000~3000: {"M", "MM", "MMM"}.

class Solution {
public:
  int romanToInt(string s) {
    int len = s.length();
    if(len ==0) return 0;
    map<char, int> roman;
    roman['I']  = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    int  result = roman[ s[len-1] ];
    for(int i = len-2; i >=0; --i){
      if( roman[ s[i] ] >= roman[ s[i+1] ])
	result += roman[ s[i] ];
      else
	result  -= roman[ s[i] ];
    }
    return result;
  }
};

int main(void){
  Solution s;
  string str ="XCIII";
  int res = s.romanToInt(str);
  cout << res << endl;
  getchar();
  return 0;
}
