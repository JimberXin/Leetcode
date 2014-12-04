#include<iostream>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int count = 0;
    int lastlength = 0;
    const char* prev = s;
    while(*s != '\0'){
      if(*s == ' ')
	{
	  if( *prev != ' ') lastlength = count;
	  count = 0;
	}
      else
	count++;
      prev = s;
      s++;
    }
    return *prev == ' '? lastlength: count;
  }
};

int main(void){
  Solution s;
  const char* str = " a  ";
  int res = s.lengthOfLastWord(str);
  cout << res << endl;
  getchar();
  return 0;
}
