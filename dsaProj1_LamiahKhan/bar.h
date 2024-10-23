//Lamiah Khan, DSA Project 1, 03/13/2024 

//constructors - https://www.w3schools.com/cpp/cpp_constructors.asp

#ifndef BAR_H
#define BAR_H
#include "foobar.h"

//bar class inherits vals from foobar class
class bar : public foobar{
public:
  bar(std::string barName, int barPosit); 
//constructor for bar class, and get_strength function
    int get_strength(); };

#endif //BAR_H

