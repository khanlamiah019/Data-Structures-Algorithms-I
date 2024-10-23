//Lamiah Khan, DSA Project 1, 03/13/2024 

//getters and setters - w3schools https://www.w3schools.com/cpp/cpp_strings_length.asp
//constructors - https://www.w3schools.com/cpp/cpp_constructors.asp

#include "bar.h"
using namespace std; 

//the following is a bar class constructor. inherited from foobar class.
bar::bar(std::string barName = "", int barPosit = 0)
:foobar(barName, barPosit){}

//calculates the strength of bars
int bar::get_strength(){
  return posit + 15;}
