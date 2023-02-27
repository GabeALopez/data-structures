// C++ program to check for balanced brackets.
#include <bits/stdc++.h>

#include <fstream>
#include <vector>

using namespace std;
// Function to check if brackets are balanced
int areBracketsBalanced(string expr) {

  // Declare a stack to hold the previous brackets.
  stack < char > temp;
  vector<int> holdPositions;
  int holdVectNum = 0;
  int position = 0;
  int current = 0;
  int previous = 0;
  
  if(expr[0] == ']' || expr[0] == ')' || expr[0] == '}')
  {

    return 1;

  }

  for (int i = 0; i < expr.length(); i++) {
    if(expr[i] != '(' & expr[i] != ')' & expr[i] != '[' & expr[i] != ']' & 
      expr[i] != '{' & expr[i] != '}')
    {
        continue;
    }
    else if (temp.empty()) {
      // If the stack is empty
      // just push the current bracket
      temp.push(expr[i]);
      holdPositions.push_back(i);
      //position = i;
    } 
    else if ((temp.top() == '(' && expr[i] == ')') ||
      (temp.top() == '{' && expr[i] == '}') ||
      (temp.top() == '[' && expr[i] == ']')) 
    {
      // If we found any complete pair of bracket
      // then pop
      
      holdPositions.pop_back();

      temp.pop();
      

     
    } 
    else if((temp.top() == ')') ||
      (temp.top() == '}') ||
      (temp.top() == ']'))
    {

      //position = i;
      
    }
    else 
    {
    temp.push(expr[i]);

    holdPositions.push_back(i);


    position = i;

    }
}
if (temp.empty()) {
  // If stack is empty return true
  return -1;
}



/*
for(int i = 0; i < expr.length(); i++)
{

  
  if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
  {

    return i+1;

  }
  

}
*/


return holdPositions.back()+1;

}



// Driver code
int main() {
  string expr = "([)";

  string line;
  ifstream myFile("allTexts.txt");
  if (myFile.is_open()) {

    while (getline(myFile, line)) {

      // Function call
      if (areBracketsBalanced(line) == -1)
        cout << "Success" << endl;
      else {
        //givePosition(line);
        cout << areBracketsBalanced(line) << endl;
      }
      //cout << "Not Balanced" << endl;

    }
    myFile.close();

  }

  return 0;
}
