//Last Modified:  2014/12/22
//Author: Junbo Xin

/*
****************************************Problem Description********************************
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. 
Sorry about that.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> result ;
    int size = 1<< n;
    result.resize(size);
    for(int i = 0; i < size; i++){
      int temp = i ^ i >>1;
      result[i] = temp;
    }
    return result;
  }
};


int main(void){
  Solution s;
  vector<int> res = s.grayCode(3);
  for(vector<int>::iterator it = res.begin(); it != res.end(); it++)
    cout << *it << endl;
  getchar();
  return 0;
	    
}
