#include<iostream>
using namespace std;

class Solution {
public:
  int sqrt(int x) {
    if(x ==0)
      return 0;
    double pre;
    double cur = 1;
    do{
      pre = cur;
      cur = (pre + x/pre)/2;
    } while( abs(pre - cur)  > 0.00001);
    return (int)cur;
  }
};


int main(void){
  Solution s;
  int res = s.sqrt(100000002);
  cout << res << endl;
  getchar();
  return 0;
}
