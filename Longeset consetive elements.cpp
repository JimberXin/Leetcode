#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
          map<int,bool>  Hash;
		  int maxNum = 0;
		  for(int i=0; i< num.size(); i++)
			  Hash[num[i]] = true;
		  for(int j=0; j < num.size(); j++){
			    if(Hash[num[j]]){
					 Hash[num[j]] = false;
					 int count = 1;
					 int left = num[j] -1,  right = num[j] + 1;
					 while( Hash.find(left) != Hash.end() ){
						    Hash[left--] = false;
							count ++;
					 }
					 while( Hash.find(right) != Hash.end()){
						    Hash[right++] = false;
							count++;
					 }
					 maxNum = max(maxNum, count);
				}
		  }
		  return maxNum;
    }
};

int main(void){
	  Solution s;
	  int arr[] = {100,3,5,4,2,1,300,6};
	  vector<int> num;
	  for(int i = 0; i< sizeof(arr)/sizeof(int); i++)
		  num.push_back(arr[i]);
	  int  res = s.longestConsecutive(num);
	  getchar();
	  return 0;
}