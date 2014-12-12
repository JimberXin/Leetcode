#include<iostream>

using namespace std;
class Solution {
public:
  bool isPalindrome(int x) {
    if(x<0)
      return false;
    int base =1;
    while(x/base >= 10)
      base *= 10;
    while( x != 0 && (x/base == x%10 || base == 1)){
      x %= base;
      x /= 10;
      base /= 100;
    }
    if(x != 0)
      return false;
    else 
      return true;
    }
};
int main() {
  Solution s;
  int x = 10;
  cout << s.isPalindrome(x) << endl;
  getchar();
  return 0;
}
