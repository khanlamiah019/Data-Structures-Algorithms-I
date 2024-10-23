//Lamiah Khan, DSA Project 1, 03/13/2024 

//functions and pointers in c++: https://www.geeksforgeeks.org/this-pointer-in-c/

#include "foo.h"
using namespace std; 

//class constructor foo inherits from class foobar
//constructors - https://www.w3schools.com/cpp/cpp_constructors.asp
foo::foo(string fooName = "", int fooPost = 0) 
  :foobar(fooName, fooPost){}

//function to get foo's strength
int foo::get_strength(){
  return posit * 3; }

