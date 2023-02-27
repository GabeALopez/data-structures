// C++ program to check for balanced brackets.
#include <bits/stdc++.h>

#include <fstream>
#include <vector>

using namespace std;
// Function to check if brackets are balanced
int areBracketsBalanced(string expr) {

  // Declare a stack to hold the previous brackets.
  stack < char > temp;
  //Declare vector to positions
  vector<int> holdPositions;
  
  if(expr[0] == ']' || expr[0] == ')' || expr[0] == '}')
  {

    return 1;

  }

  for (int i = 0; i < expr.length(); i++) {
    //If not a brace continue
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
      
      //pop position if there is a matching brace
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

    //push postion of brace that is pushed onto stack
    holdPositions.push_back(i);



    }
}
if (temp.empty()) {
  // If stack is empty return true
  return -1;
}

return holdPositions.back()+1;

}



// Driver code
int main() {
  string expr = "([)";

  //read through file of test cases
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
