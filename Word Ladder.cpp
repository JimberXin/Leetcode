#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

//Given two words (start and end), and a dictionary, find the length of shortest transformation sequencefrom start 
//to end, such that:Only one letter can be changed at a time Each intermediate word must exist in the dictionary
//For example,  Given:
//start = "hit"    end = "cog"  dict = ["hot","dot","dog","lot","log"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//Note:
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		if(start.length() != end.length() || dict.empty())
			return 0;
        unordered_map<string ,int> dist;
		queue<string>  path;
		path.push(start);
		dist[start] = 1;
		while( !path.empty()){
			string word = path.front();
			path.pop();
			for(int i = 0; i < word.length(); ++i){
				string temp = word;
				for(char c = 'a'; c <= 'z'; ++c){
					 temp[i] = c; 
					 if(temp == end)
						return dist[word] + 1;
					 if(dict.count(temp) > 0 && dist.count(temp) == 0)
					 {
						  dist[temp] = dist[word] + 1;
						  path.push(temp);
					 }
				} // end for c
			} // end for i
		} // end for while
		if( dist.count(end) == 0) return 0;
		return dist[end];
    }
};

int main(){
	Solution s;
    unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	string start = "hit";
	string end =  "cog";
	int result = s.ladderLength(start, end, dict);
	cout << result << endl;
	getchar();
	return 0;
}

