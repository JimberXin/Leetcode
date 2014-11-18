#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;


//You are given a string, S, and a list of words, L, that are all of the same length. 
//Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and
//without any intervening characters.     For example, given:
//S: "barfoothefoobarman"     L: ["foo", "bar"]      You should return the indices: [0,9]. (order does not matter).

//Solutions: http://blog.csdn.net/doc_sgl/article/details/13022131
//for each index of i in S, add one length of each words every time, if not exist, break, if counts number overflow, break
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
         vector<int> result;
		 map<string, int> words;
		 map<string, int> cur_counts;
		 int wordNum = L.size();  
		 int wordLen = L[0].size();
		 for(int i = 0; i < wordNum;++i)
			 words[ L[i] ]++;  // counts each words' frequence in L

		 int iterNum = S.length() - wordNum*wordLen;
		 for(int i = 0; i <= iterNum; ++i)
		 {
			     int j;
			     for(j = 0; j < wordNum; ++j)
				 {
					    string temp = S.substr(i + j*wordLen, wordLen); // same length in S, from i+j*wordLen
						if(words.count(temp) == 0)
							break;  // temp does not exist in L
						cur_counts[temp]++;
						if(words[temp] < cur_counts[temp])
							break;   //temp exist 1 more times in S than in L
				 }
				 if( j == wordNum)
					 result.push_back(i);
				 cur_counts.clear();
		 }
		 return result;
    }
};

int main(){
	Solution s;
	string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string> L;
	L.push_back("fooo");
	L.push_back("barr");
	L.push_back("wing");
	L.push_back("ding");
	L.push_back("wing");
	vector<int> res = s.findSubstring(S,L);
	getchar();
	return 0;
}