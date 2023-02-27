// C++ program to check for balanced brackets.
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;
// Function to check if brackets are balanced
int areBracketsBalanced(string expr)
{
  // Declare a stack to hold the previous brackets.
  stack<char> temp;
  vector<int> positions;
  //int index = 0;
  if(expr[0] == ']' || expr[0] == ')' || expr[0] == '}'){
    return 1;
  }
  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] != '(' || expr[i] != ')' || expr[i] != '[' || expr[i] != ']' || expr[i] != '{' || expr[i] != '}'){
      continue;
    }
    else if (temp.empty()) {
      // If the stack is empty
      // just push the current bracket
      temp.push(expr[i]);
      positions.push_back(i);
    }
    else if ((temp.top() == '(' && expr[i] == ')')
    || (temp.top() == '{' && expr[i] == '}')
    || (temp.top() == '[' && expr[i] == ']')) {
    // If we found any complete pair of bracket
    // then pop
      positions.pop_back();
      temp.pop();
    }
    /*else if ((temp.top() == ')' || temp.top() == ']' || temp.top() == '}')){
      index = i;
    }*/
    else {
      temp.push(expr[i]);
      positions.push_back(i);
    }
  }
  if (temp.empty()) {
    // If stack is empty return true
    return -1;
  }
  return positions.back() + 1;
}
// Driver code
int main()
{
  string expr = "[{{}}]";
  string line;
  ifstream All_Cases("allTexts.txt");
  if(All_Cases.is_open()){
    while(getline(All_Cases, line)){
      if(areBracketsBalanced(expr) == -1){
        cout << "Success" << endl;
      }
      else {
        cout << areBracketsBalanced(expr) << endl;
      }
    }
    All_Cases.close();
  }

  return 0;
}