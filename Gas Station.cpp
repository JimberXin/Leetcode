//Last Modified:  2014/12/22
//Author:  Junbo Xin

/*
*****************************Problem Description********************************
There are N gas stations along a circular route, where the amount of gas 
at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
 from station i to its next station (i+1). You begin the journey with an empty 
tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once,
 otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int  resGas = 0;
    int start = 0;
    for(int i=0; i<gas.size(); i++){
      resGas += gas[i] - cost[i];
      if(resGas < 0){
	resGas = 0;
	start = i+1;  //jump to i+1
      }
    }
    if(start >= gas.size())
      return -1;
    int j= start, num = 0;
    resGas = 0;
    while( num < gas.size()){
      resGas += gas[j] - cost[j];
      if(resGas < 0)
	return -1;
      num++;
      j = (j+1)%gas.size();
    }
    return start;		  
  }
};

int main(void){
  Solution s;
  int arr1[] = {4};
  int arr2[] = {3};
  vector<int> num1, num2;
  for(int i=0; i<sizeof(arr1)/sizeof(int);i++){
    num1.push_back(arr1[i]);
    num2.push_back(arr2[i]);
  }
  int res = s.canCompleteCircuit(num1,num2);
  cout << res << endl;
  getchar();
  return 0;
}
