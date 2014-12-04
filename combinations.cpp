#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  //Num is the left number, max to k; k == k,  max == n; 
  void DFS( int Num, int k,  int max, int index, vector<int> temp, vector<vector<int> > &result){
    if(Num == 0){
      result.push_back(temp);
      return;
    }
    for(size_t i=index; i <= max; i++){
      temp.push_back(i);
      DFS(Num-1, k, max,  i+1, temp,result);  
      temp.pop_back();   
    }
  }
  
  vector<vector<int> > combine(int n, int k){
    vector<vector<int> > final;
    vector<int> tempResult;
    DFS(k, k , n, 1,tempResult, final);
    return final;    
  }
};


int main()
{
  Solution s;
  vector<vector<int> >  reuslt = s.combine(1,0);
  getchar();
  return 0;
}
