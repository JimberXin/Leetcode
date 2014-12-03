#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int step = 4; //every integer define 4 bits of char
const int Big = 10000; // overflow base

class Solution {
public:
  void convert(string number, vector<int> & arr){
		   
  }
  string multiply(string num1, string num2) {
    int n1 = num1.length();
    int n2 = num2.length();
    string result(n1+n2, '0');
    if(num1 == "0" || num2 == "0") 
      return "0";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for(int i = 0; i < n1; ++i){
      for(int j = 0; j < n2; ++j){
	int temp = (num1[i] - '0') *( num2[j] - '0') + result[i+j] - '0';
	if( temp >= 10){
	  result[i+j+1] = (result[i+j+1] -'0') + temp/10+ '0';
	  result[i+j] = temp %10  + '0';
	}else
	  result[i+j] = temp + '0';
      }
    }	
    reverse(result.begin(), result.end());
    while(result[0] == '0')
      result.erase(result.begin());
    return result;
  }
};

int main(){
  Solution s;
  string num1 = "0";
  string num2 = "0";
  string result = s.multiply(num1, num2);
  cout << result << endl;
  getchar();
  return 0;
}
