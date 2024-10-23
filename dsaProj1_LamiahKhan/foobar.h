//Lamiah Khan, DSA Project 1, 03/13/2024 

//access specifiers: https://www.w3schools.com/cpp/cpp_access_specifiers.asp 
//functions and pointers in c++: https://www.geeksforgeeks.org/this-pointer-in-c/

#ifndef FOOBAR_H
#define FOOBAR_H
#include <iostream>
#include <string>

//declaring foobar base class, where each element has name and position. 
class foobar{
  std::string name;
  int curPos; 

//positions can be inhertied by child classes
  protected:
  int posit;  
  public:

//declaring constructor for foobar class
//constructors - https://www.w3schools.com/cpp/cpp_constructors.asp
  foobar(std::string foobName, int foobPos); 

//virtual func
//virtual func - https://www.geeksforgeeks.org/virtual-function-cpp/
  virtual int get_strength();

//public member func
  foobar& set_position(int position);
  std::string get_name(void); };

#endif //FOOBAR_H

