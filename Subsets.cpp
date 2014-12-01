#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  void DFS(vector<int> &S, int index, vector<int> temp, vector<vector<int> > &result){
    if(index == S.size()){
      result.push_back(temp);
      return;
    }

    DFS(S, index+1, temp, result); //not include current element
    temp.push_back(S[index]);
    DFS(S, index+1, temp, result); //include current element
			
	}

  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    int len = S.size();
    vector<int> singleRes;
    vector<vector<int> > res;
    DFS(S, 0, singleRes, res);
    return res;  
  }
};

int main(void){
  Solution s;
  int arr[] = {1,2,3};
  vector<int> num;
  for(int i=0; i<sizeof(arr)/sizeof(int); i++)
    num.push_back(arr[i]);
  vector<vector<int> > res = s.subsets(num);
  getchar();
  return 0;
}
