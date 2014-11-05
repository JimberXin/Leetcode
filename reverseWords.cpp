#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) 
    {
        //
		 if(s.size() == 0 )
			 return;
          stack<string> strStack;
		  string::iterator it = s.begin();	
		  string word;
		   while(it != s.end())
		  {
			    // remove the space before the word begins or between the words
			    while( it != s.end() && *it == ' ')
			      it++;
			      while( it != s.end() && *it != ' ' )
					  word.push_back(*it++);
				  strStack.push(word);
				  word.clear();
		  }
		  s.clear();
		  while(!strStack.empty())
		  {
			  s += strStack.top() ;
			  s += ' ';
			  strStack.pop();
		  }
		  s.erase(s.end()-1);
		  if(s.size() != 0 && s[0] == ' ')
		         s.erase(s.begin());  // remove the space before the new string s
	
        //     
    }
};

int main(void)
{
	Solution s;
	string test =  " ";
	//string test = "         ";
	s.reverseWords(test);
	string::size_type number = test.size();
	getchar();
	return 0;
}