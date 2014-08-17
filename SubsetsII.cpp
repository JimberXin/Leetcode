#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void DFS(vector<int> &S, int index, vector<int>&temp, vector<vector<int> >& result){
		  result.push_back(temp);
		  for(int i = index;  i < S.size();  i++){
			  if(i != index && S[i] == S[i-1]) continue;
			  temp.push_back(S[i]);
			  DFS(S, i+1, temp, result);
			  temp.pop_back();
	}
	}
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(),S.end());
		vector<vector<int> > res;
		vector<int> temp;
		DFS(S,0,temp, res);
		return res;
    }
};

int main(void){
	Solution s;
	int arr[] = {1,2,3};
	vector<int> num;
	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		num.push_back(arr[i]);
	vector<vector<int> > res = s.subsetsWithDup(num);
	getchar();
	return 0;
}