#include<iostream>
#include<map>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
  bool isValid(string s) 
  {
    typedef map<char, int>::value_type valType;
    map<char,int> ValidPar;
    stack<char> par;
    ValidPar.insert(valType('(',1));
    ValidPar.insert(valType('[',2));
    ValidPar.insert(valType('{',3));
    ValidPar.insert(valType(')',4));
    ValidPar.insert(valType(']',5));
    ValidPar.insert(valType('}',6));
    string::iterator it;
    for(it = s.begin(); it != s.end(); it++)
      {
	if(*it == '(' || *it == '[' || *it == '{')
	  par.push(*it);
	else
	  {
	    //int big = ValidPar[*it];
	    //int small = par.top();
	    if( par.empty() ||  ( ValidPar[*it] -ValidPar[par.top()] ) != 3)
	      return false;
	    else
	      par.pop();
	  }		   
      }
    if(par.empty())
      return true;
    else
      return false;   
  }
};

int main()
{
  Solution s;
  string str = "(";
  bool result = s.isValid(str);
  getchar();
  return 0;
}
