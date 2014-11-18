#include<iostream>
#include<vector>
#include<string>
using namespace std;


//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully 
//(left and right) justified.  You should pack your words in a greedy approach; that is, pack as many words as you
//can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do 
//not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//For the last line of text, it should be left justified and no extra space is inserted between words. For example,
//words: ["This", "is", "an", "example", "of", "text", "justification."]   L: 16.
//Return the formatted lines as:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]
//Note: Each word is guaranteed not to exceed L in length.
//Corner Cases:
//A line other than the last line might contain only one word. What should you do in this case?
//In this case, that line should be left-justified.

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
         int curNum = 0;
		 //words.push_back("");   // as the end of the words
		 int wordsNum = words.size();
		 vector<string> result;
		 vector<string> eachLine;
		 for(int i = 0; i < wordsNum; ++i){
			 if(curNum + eachLine.size() + words[i].length() <= L)
			 {
				 eachLine.push_back(words[i]);
				 curNum += words[i].length();
			 }
			 else // the current line cannot add words, push it in the result, divide into 3 cases.
			 {
				 string temp; 
				 //has only one word, left justification
				 if(eachLine.size() == 1) 
				   {
					    temp = eachLine[0] + string(L-eachLine[0].size(),' ');
						result.push_back(temp);
						eachLine.clear();
						eachLine.push_back(words[i]);
						curNum = words[i].length();
				   }
				 //otherwise, divide the space between the words
				 else
				 {
					   int spaceNum =  L - curNum;
					   int eachSpace =  spaceNum / (eachLine.size() -1); // space between each words
					   int leftNum = spaceNum%(eachLine.size()-1);
					   string leftSpace (eachSpace+1,' ');
					   string rightSpace(eachSpace, ' ');
					   for(int i = 0; i < leftNum;++i)
						   temp += eachLine[i] + leftSpace;
					   for(int i = leftNum; i < eachLine.size()-1; ++i)
						   temp += eachLine[i] + rightSpace;
					   temp += eachLine[eachLine.size()-1]; // the last word has no need to add space after it
					   result.push_back(temp);
					   eachLine.clear();
					   eachLine.push_back(words[i]);
					   curNum = words[i].length();
				 }
			 }
		 }// end for i
		 		 //reach the last Line
		              curNum = 0;
					   string temp;
					   for(int i = 0; i < eachLine.size() - 1; ++i){
						   temp += eachLine[i] + " ";
						   curNum += eachLine[i].length() + 1;
					   }
					   temp += eachLine[eachLine.size()-1];
					   temp += string(L - curNum -eachLine[eachLine.size()-1].length(), ' ');
					   result.push_back(temp);
		 return result;
    }
};

int main(){
	Solution s;
	//string arr[] = {"This", "is", "an", "example", "of", "text", "justification."};
	string arr[] = {"Imagination","is","more","important","than","knowledge."};
	vector<string> words;
	for(int i = 0; i < sizeof(arr)/sizeof(string);++i)
		words.push_back(arr[i]);
	vector<string> res = s.fullJustify(words,11);
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	getchar();
	return 0;
}