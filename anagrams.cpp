#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

//Given an array of strings, return all groups of strings that are anagrams.
//Note: All inputs will be in lower-case.
//For example:
//Input:¡¡  ["tea","and","ate","eat","den"]
//Output:   ["tea","ate","eat"]

//Solution: hastTable records the string that has exist
//1)Traversing through all the strings, and sort the current string
//2)if the i-th string has not yet exist, add it in the hashTable
//3)if the i-th string has exist, and its index is not -1,
//that means this is the second time the string 
//exists, add the previous one, and the current one, and reset the index as -1
class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    int n = strs.size();
    map<string, int> hashTable;
    vector<string> result;
    for(int i = 0; i < n; ++i){
      string temp = strs[i];
      sort(temp.begin(), temp.end());
      map<string, int>::iterator it = hashTable.find(temp);
      if( it == hashTable.end() ) // not find
	hashTable[temp] = i;
      else  // find the string existed in the hashTable
	{
	  if(hashTable[temp] == -1)
	    result.push_back(strs[i]);
	  else{
	    result.push_back(strs[hashTable[temp]]);//add the string that first emerges
	    hashTable[temp] = -1;
	    result.push_back(strs[i]);
	  }
	}
    }//end for
    return result;
  }
};
int main(){
  Solution s;
  vector<string> strs;
  string str[] ={"ate", "and", "nda", "tae","hala","bek","eta"};
  for(int i = 0; i < sizeof(str)/sizeof(string);++i)
    strs.push_back(str[i]);
  vector<string> result = s.anagrams(strs);
  getchar();
  return 0;
}
