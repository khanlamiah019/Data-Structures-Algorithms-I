//Lamiah Khan, DSA Project 1, 03/13/2024 

//credit for this portion of the code (similar structure):     
//parse_file:https://stackoverflow.com/questions/47126273/converting-parameter-pack-into-a-vector 
//getters and setters - w3schools https://www.w3schools.com/cpp/cpp_strings_length.asp
//file_ops in c++: https://www.mygreatlearning.com/blog/file-handling-in-cpp/

#include <vector>
#include <fstream>
#include <sstream>
#include "file_ops.h"
#include "foobar.h"
#include "foo.h"
#include "bar.h"
using namespace std;

//function for reading input file
//function for reading input: https://stackoverflow.com/questions/15101453/using-getline-to-read-from-text-file-leads-to-infinite-loop-when-check-is-eof
//stringline: https://www.geeksforgeeks.org/stringstream-c-applications/
void parse_file(string fileName, vector<foobar *> *fVector){
  ifstream f(fileName); 
  string line = ""; 
  if(f.is_open()) {
     while(!f.eof()) {
      getline(f, line);
    
    if(line.empty()) {return;}
      stringstream s(line);
      string word = "", foobVal = "", name = ""; 

      //int count benefits: https://www.careercup.com/question?id=13716677
      int count = 0;    
      while(s >> word) {
      count == 0 ? foobVal = word : name = word; 
      count++;}
      fVector->push_back(pack_vector(foobVal, word)); }}}

//function for writing to output.txt
//writing to output file: https://cplusplus.com/doc/tutorial/files/
void write_file(vector<foobar *> fVector){
  ofstream f; 
  f.open("output.txt");
  for(size_t i = 0; i < fVector.size(); i++) {
    f << fVector[i]->get_name() << " " << fVector[i]->get_strength() << "\n"; }
  f.close();}
//will write out name, strength on txt file. 

//function for creating objects based on input file. 
foobar *pack_vector(string foobVal, string name){
  //specifically, each object targets the first words from each command of file (0) 
  if(foobVal.compare("foobar") == 0) {
    foobar *foob = new foobar(name, 0);
    return foob;}
  
  if(foobVal.compare("foo") == 0) {
    foo *fo = new foo(name, 0); 
    return fo;}
  
  if(foobVal.compare("bar") == 0) {
    bar *ba = new bar(name, 0);
    return ba;}
      return NULL;}

//function for assigning positions. size_t is max size of array. 
void assign_positions(vector<foobar *> fVector){
  for(size_t i = 0; i < fVector.size(); i++) {
    fVector[i]->set_position(fVector.size() - i); }}

