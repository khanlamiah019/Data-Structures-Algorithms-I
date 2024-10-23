//Lamiah Khan, DSA Project 1, 03/13/2024 

//getters and setters - w3schools https://www.w3schools.com/cpp/cpp_strings_length.asp
//constructors - https://www.w3schools.com/cpp/cpp_constructors.asp
//functions and pointers in c++: https://www.geeksforgeeks.org/this-pointer-in-c/

#include "foobar.h"
using namespace std; 

//foobar class constructor
foobar::foobar(string foobName = "", int foobPos = 0){
  name = foobName; 
  curPos = foobPos;}

//function to return foobar's name
string foobar::get_name(){
  return name;}

//class func and pointer that returns position of foobar. 
foobar &foobar::set_position(int position){
  curPos = position;
  posit = curPos; 
  return *this;}

  //funct that gets and returns foobar's strength
int foobar::get_strength(){
  return posit;}

