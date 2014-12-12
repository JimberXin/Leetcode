#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
  bool  wordBreakHelper(string s, unordered_set<string> &dict, set<string> &unmathed, int maxL, int minL){
    if(s.empty()) return true;
    int i = maxL > s.length()? s.length() : maxL;
    for(; i > 0 ; i--)
      {
	string preffixstr = s.substr(0,i);
	if( dict.find(preffixstr) != dict.end() ){
	  string suffixstr = s.substr(i);
	  if(unmathed.find(suffixstr) != unmathed.end() )
	    continue;
	  else 
	    if(wordBreakHelper(suffixstr,dict,unmathed,maxL,minL) )
	      return true;
	    else
	      unmathed.insert(suffixstr);
	}
      }
    return false;
  }

  bool wordBreak(string s, unordered_set<string> &dict) {
    if(s.length() == 0) return true;
    if(dict.empty()) return false;
    unordered_set<string>::iterator it = dict.begin();
    int maxLen = (*it).length(), minLen = (*it).length();
    for(; it != dict.end(); it++)
      {
	if((*it).length() > maxLen)
	  maxLen = (*it).length();
	else if((*it).length() < minLen)
	  minLen = (*it).length();
      }
    set<string> unmathed;  // records the words that are not matched.
    return wordBreakHelper(s,dict,unmathed,maxLen,minLen);
  }
};

int main(void){
  Solution s;
  string str = "leetcode";
  unordered_set<string> dictinary;
  dictinary.insert("leet");
  dictinary.insert("cod");
  bool isTrue = s.wordBreak(str,dictinary);
  cout << isTrue << endl;
  getchar();
  return 0;
}


//
//bool wordBreak(string s, unordered_set<string> &dict) {  
//    vector<bool> wordB(s.length() + 1, false);  
//    wordB[0] = true;  
//    for (int i = 1; i < s.length() + 1; i++) {  
//        for (int j = i - 1; j >= 0; j--) {  
//            if (wordB[j] && dict.find(s.substr(j, i - j)) != dict.end()) {  
//                wordB[i] = true;  
//                break; //  
//            }  
//        }  
//     }  
//    return wordB[s.length()];  
//   }  
