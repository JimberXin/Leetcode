#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
  string intToRoman(int num){
    //************create hashTable*****************
    map<int,string> bit, ten, hud, thd;
    typedef map<int,string>::value_type Type;
    string first[]  =  {"I", "II", "III","IV","V","VI","VII","VIII","IX"};
    string second[]  =   {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string third[]  =   {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string four[] =   {"M","MM","MMM"};
    int digit[]    =  { 1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < 9; i++) {
	bit.insert(Type(digit[i], first[i]));
	ten.insert(Type(digit[i], second[i]));
	hud.insert(Type(digit[i], third[i]));
	if( i < 3)
	  thd.insert(Type(digit[i], four[i]));
      }
    vector<string> result;
    int  Bits = 0;
    int count = 0;
    while(num != 0){
      if(  num %10 != 0  )
	{
	  if(count == 0 && num % 10 != 0)
	    result.insert(result.begin(), bit.find(num % 10)->second);
	  else if(count ==1)
	    result.insert(result.begin(), ten.find(num % 10)->second);
	  else if(count == 2)
	    result.insert(result.begin(), hud.find(num % 10)->second);
	  else
	    result.insert(result.begin(), thd.find(num % 10) ->second);
	}
      count++;
      num /= 10;			   
    }
    string convertStr;
    for(size_t i = 0;  i < result.size();  i++)
      convertStr += result[i];
    return convertStr;		  
  }
};

int main(void)
{
  Solution s;
  string result = s.intToRoman(703);
  cout << result << endl;
  getchar();
  return 0;
}
