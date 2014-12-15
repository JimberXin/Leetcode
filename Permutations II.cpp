#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/************************************Permutations II*********************************
Given a collection of numbers that might contain duplicates,
return all possible unique permutations.
For example, [1,1,2] have the following unique permutations
[1,1,2], [1,2,1], and [2,1,1].

 */
class PermutationsII {
public:
  bool isVisted[200];
  void DFS(vector<vector<int> >&result,vector<int> &temp,vector<int> &num,int index){
    if(temp.size() == num.size()){
      result.push_back(temp);
      return;
    }
    
    for(int i = 0; i < num.size(); ++i){
      if(! isVisted[i] ){
	if( i != 0 && num[i] == num[i-1] && !isVisted[i-1] )   // Important!
	  continue;   
	temp.push_back(num[i]);
	isVisted[i] = true;   //marked the current num as visited
	DFS(result, temp, num, i+1);  //deep search
	isVisted[i] = false;  //restore
	temp.pop_back();
      }
    }
  }
  vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > all;
    vector<int> temp;
    sort(num.begin(), num.end()); // different from permutation, must sort first
    memset(isVisted, false, sizeof(isVisted));
    DFS(all, temp, num, 0);
    return all;
  }
};

//**************************test*********************************
int main(void){
  PermutationsII p;
  int arr[] = {1,1,1,2,4};
  vector<int> num;
  for(int i=0; i< sizeof(arr)/sizeof(int);i++)
    num.push_back (arr[i]);
  vector<vector<int> > result = p.permuteUnique(num);
  vector<vector<int> >::iterator outside;
  vector<int>::iterator inside;
  for(outside=result.begin(); outside != result.end(); outside++){
    for(inside = outside -> begin(); inside != outside -> end(); inside++)
      cout << *inside << " " ;
    cout << endl;
  }
  
  getchar();
  return 0;
}
