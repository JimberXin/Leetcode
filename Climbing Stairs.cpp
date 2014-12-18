//Last Modified: 2014/12/18
//Author: Junbo Xin

/*
************************Problem Description**************************
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int*d = new int[n+1];
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i < n+1; i++)
      d[i] = d[i-1] + d[i-2];
    return d[n];
  }
};

int main(void){
  Solution s;
  int number = s.climbStairs(5);
  cout << number << endl;
  getchar();
  return 0;
}
