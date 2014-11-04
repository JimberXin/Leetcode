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