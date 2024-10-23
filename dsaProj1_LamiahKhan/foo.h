//getters and setters - w3schools https://www.w3schools.com/cpp/cpp_strings_length.asp
//Lamiah Khan, DSA Project 1, 03/13/2024 

//functions and pointers in c++: https://www.geeksforgeeks.org/this-pointer-in-c/

#ifndef FOO_H
#define FOO_H
#include "foobar.h"
//similar to bar commands
//the following is a foo class constructor. it inherits from foobar class. 
//constructors - https://www.w3schools.com/cpp/cpp_constructors.asp

class foo : public foobar{
  public:
  foo(std::string fooName, int fooPost); 
  int get_strength(); };

#endif //FOO_H


