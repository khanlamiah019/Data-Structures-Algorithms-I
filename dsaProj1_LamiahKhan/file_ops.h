//Lamiah Khan, DSA Project 1, 03/13/2024 

//file_ops in c++: https://www.mygreatlearning.com/blog/file-handling-in-cpp/
#ifndef FILE_OPS_H
#define FILE_OPS_H
#include <vector>
#include "foobar.h"
using namespace std; 

//function prototypes
//parse file: https://stackoverflow.com/questions/60245936/how-do-i-parse-this-file-in-cpp
foobar *pack_vector (string foobVal, string name); 
void parse_file (string fileName, vector<foobar *> *fVector);
void assign_positions (vector<foobar *> fVector); 
void write_file (vector<foobar *> fVector); 

#endif //FILE_OPS_H

