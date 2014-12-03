#include<iostream>
#include<stack>
#include<string>
using namespace std;

class MinStack {
public:
  void push(int x) {
    mainStk.push(x);
    if(helpStk.empty() || helpStk.top() >=  x) //  >=, not  >
      helpStk.push(x);
  }

  void pop() {
    if(mainStk.empty()) 
      return;
    if(mainStk.top() == helpStk.top())
      helpStk.pop();
    mainStk.pop();
  }

  int top() {
    return mainStk.top();
  }

  int getMin() {
    return helpStk.top();
  }

private:
  stack<int> mainStk;
  stack<int> helpStk;
};

int main(){
  MinStack stk;
  stk.push(3);
  stk.push(1);
  stk.push(8);
  int minS = stk.getMin();
  stk.push(7);
  stk.pop();
  stk.pop();
  stk.push(12);
  minS = stk.getMin();
  getchar();
  return 0;
}
