#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

//Given a digit string, return all possible letter combinations that
//the number could represent.
//A mapping of digit to letters (just like on the telephone buttons)
//is given below.
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
class Solution {
public:
  map<char, string> hashTable;
public:	
  void DFS(string digits, string &path, vector<string> &result, int index){
    int n = digits.length();
    if(index == n){
      result.push_back(path);
      return;
    }

    for(int j = 0; j < hashTable[ digits[index] ].length(); ++j){
      path += hashTable[ digits[index] ][j];
      DFS(digits, path, result, index+1);
      path.erase(path.end()-1);
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> result;
    string path;
    int n = digits.length();
    if(n == 0) {
      result.push_back(path);
      return result;
    }
    hashTable['2'] = "abc";
    hashTable['3'] = "def";
    hashTable['4'] = "ghi";
    hashTable['5'] = "jkl";
    hashTable['6'] = "mno";
    hashTable['7'] = "pqrs";
    hashTable['8'] = "tuv";
    hashTable['9'] = "wxyz";
    DFS(digits, path, result, 0);
    return result;
  }
};

int main()
{
  Solution s;
  string str = "";
  vector<string> res = s.letterCombinations(str);
  for(int i = 0; i < res.size(); ++i){
    cout << res[i] << endl;
  }
  getchar();
  return 0;
}
