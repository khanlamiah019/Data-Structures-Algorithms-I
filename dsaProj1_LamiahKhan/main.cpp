//Lamiah Khan, DSA Project 1, 03/13/2024 

//user input in c++:
// https://stackoverflow.com/questions/42025936/opening-a-file-based-on-user-input-c

#include "file_ops.h"
using namespace std; 

int main(){
  //creating vector for foobar pointer
  vector<foobar *> fVector; 
  string fileName;
  
  //user input for file name
  cout << "Enter name of input file: " << "\n"; 
  cin >> fileName; 
  
  //command reads input file
  parse_file(fileName, &fVector); 
  
  //assigns positions input file
  assign_positions(fVector); 
  
  //writes out on a textfile, output.txt
  write_file(fVector);  
  return 0; }

//coded on VS Code, and then run in replit. 
//some of the code was implemented from w3schools, geeksforgeeks, and stack overflow! 
//it is creditted when it was used. 
