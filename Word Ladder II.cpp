#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

//Given two words (start and end), and a dictionary, find all shortest transformation sequence(s)
//from start to end, such that: Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example, Given:  start = "hit"  end = "cog"  dict = ["hot","dot","dog","lot","log"]
//Return[    ["hit","hot","dot","dog","cog"],   ["hit","hot","lot","log","cog"]  
//Note: 1)All words have the same length.
//2) All words contain only lowercase alphabetic characters.

//Solutions: 
//https://oj.leetcode.com/discuss/10875/word-ladder-ii-tried-bfs-and-dfs-but-still-getting-tle
class Solution {
public:
  void DFS(string end,  int step, vector<vector<string> >&result, vector<string> &temp,
    unordered_map<string, vector<string> >&graph){
       if(step == 0){
	 temp.push_back(end);
	 result.push_back( vector<string>(temp.rbegin(),temp.rend()) );
	 temp.pop_back();
	 return;
       }

       temp.push_back(end);
       vector<string>::iterator it = graph[end].begin();
       for(; it != graph[end].end(); ++it)
	 DFS(*it, step-1, result, temp, graph);
       temp.pop_back();
  }

  vector<vector<string> >  findLadders(string start, string end, unordered_set<string> &dict) {
    unordered_map<string ,int> dist;
    unordered_map<string, vector<string> > map;
    typedef pair<string, vector<string> > valType;
    int minDist = INT_MAX;
    queue<string>  path;
    path.push(start);
    dist.insert( pair<string, int>(start, 1) ); // add the start string
    dict.insert(end); // add the end string in the dictinary.
    //BFS
    while( !path.empty())
      {
	string word = path.front();
	path.pop();
	if(word == end ){
	  minDist = dist[end];
	  continue;
	}
	int curDist = dist[word] + 1;
	if(curDist > minDist) break;
	for(int i = 0; i < word.length(); ++i){
	  string temp = word;
	  for(char c = 'a'; c <= 'z'; ++c){
	    temp[i] = c; 
	    //find the temp exist in the dictinary, but not yet in the dist, add it in the dist
	    if(dict.count(temp) >0 && dist.count(temp) == 0)
	      {
		dist.insert( pair<string, int>(temp, curDist));
		path.push(temp);
		vector<string> tempPath(1, word);
		map.insert(pair<string, vector<string> >( temp, tempPath) );
		continue;
	      }
	    //find the temp exist in the dictianry and also in the dist
	    else if( dict.count(temp) >0 && dist.count(temp) >0)
	      {
		if( dist[temp] == curDist )
		  map[temp].push_back(word);
	      }
	  } // end for c
	} // end for i
      } // end for while
      
    vector<vector<string> > result;
    vector<string> builder;
    if(map.find(end) != map.end())
      DFS(end, minDist-1, result, builder, map);
    return result;
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
  vector<vector<string> > result;
  result = s.findLadders(start, end, dict);
  //cout << result << endl;
  getchar();
  return 0;
}

