#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) 
    {
		stack<int> OPND;
		int result = 0;
		for(size_t i =0; i<tokens.size(); i++)
		{
		    if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		    {
				int  rOPND = OPND.top();
			    OPND.pop();
				int lOPND = OPND.top();
				OPND.pop();
				if(tokens[i] == "+")
					result =  lOPND + rOPND;
				else  if(tokens[i] == "-")
					result =  lOPND - rOPND;
				else  if(tokens[i] == "*")
					result =  lOPND * rOPND;
				else  if(tokens[i] == "/")
					result =  lOPND / rOPND;
				 
				OPND.push(result);
		    }
		    else
				OPND.push(atoi(tokens[i].c_str()));
		}

		return OPND.top();


	}
};

int main()
{
	Solution s;
	vector<string> expression;
	string str[] = {"0", "3", "-"};
    //cout <<sizeof(str)/sizeof(string)<< endl;
	for(size_t i=0; i<sizeof(str)/sizeof(string);i++)
		expression.push_back(str[i]);
	int result =  s.evalRPN(expression);
	cout << result << endl;
	getchar();
	return 0;
}