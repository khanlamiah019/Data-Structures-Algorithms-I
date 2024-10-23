#include <iostream> 
#include <string.h>

#include <sstream>
#include <fstream>
#include <vector>
#include <list>

using namespace std; 

//constructor for function that parses a file
void parse_file(string input_file, string output_file);

int main() {

  string input_file, output_file;

  //input file
  cout << "input file name: " << "\n"; 
  cin >> input_file; 

  //output file
  cout << "output file name: " << "\n"; 
  cin >> output_file;

  //will parse the input file, perform operations, and write to output file
  parse_file(input_file, output_file); 

  return 0; 
}


//simple list class that implements a singly linked list 
//classes that inherit this class can use the append, prepend and dequeue functions
template <typename T> class SimpleList {

  private:

    //node struct used for singly linked list operations
    struct Node { 
      T data;
      Node *next;

      Node(const T &d, Node *n = nullptr ) {

        data = d;
        next = n; 
      }
    };

    string list_name; 
    int list_size; 
    Node *tail; 
    Node *head; 

  public:
    SimpleList(string name){tail = nullptr; head = nullptr; list_size = 0; list_name = name;} 
    string get_list_name() { return this->list_name; }
    int get_list_size() { return this->list_size; }

    //to be implemented by children classes
    virtual int push_list(T d) = 0; 
    virtual T pop_list() = 0; 

  //accessible to children classes
  protected:
    int append_list(T d);  //add to end
    int prepend_list(T d); 
    T rm_front_list(); 
};


//append list adds an element to the end of a list
template <typename T> int SimpleList<T>::append_list(T d) {

  //creates new node with data d and sets the next node to be null
  Node *new_node = new Node(d);
  new_node->next = nullptr;

  //if there's an element in the list it sets the current tail's next node to the new node
  //otherwise if the list is empty it sets the head and the tail to the new node
  tail = (tail) ? tail->next = new_node : head = new_node;
  list_size++;
  return 0; 
}

//prepend list adds an element to the start of a list
template <typename T> int SimpleList<T>::prepend_list(T d) {

  //creates new node with data d and sets the next node equal to the head
  Node *new_node = new Node(d);
  new_node->next = head;

  //if there's an element in the list it sets the head to the new node
  //otherwise if the list is empty it sets the head and the tail to the new node
  head = (head) ? new_node : tail = new_node;
  list_size++; 
  return 0; 
}


//rm front list removes an element from the front of a list
template <typename T> T SimpleList<T>::rm_front_list() {

  //creating temp node to store data to be deleted
  Node *tmp = head;
  T data = head->data;

  // move the head to the next node if it exists
  head = (head->next) ? head->next : tail = nullptr;
  list_size--;

  //frees the current head
  delete tmp;

  //returns the popped data value
  return data;
}




//stack class that inherits the SimpleList class
template <typename T> class Stack : public SimpleList<T> {

  public:
    Stack(string l_name); //stack constructor
    //pushing for a stack is the same as prepending a list
    int push_list(T d) { return this->prepend_list(d); } 
    //popping a stack removes the first element
    T pop_list() { return this->rm_front_list(); }
};

//constructor for stack creates a simple list with a name
template <typename T> Stack<T>::Stack(string l_name) 

  :SimpleList<T>(l_name) {
}


//queue class that inherits the SimpleList class
template <typename T> class Queue : public SimpleList<T> {

  public:
    Queue(string l_name); 
    //pushing for a queue is the same as appending a list
    int push_list(T d) { return this->append_list(d); }
    //popping a queue removes the first element
    T pop_list() { return this->rm_front_list(); }
};

//constructor for stack creates a simple list with a name
template <typename T> Queue<T>::Queue(string l_name) 

  :SimpleList<T>(l_name) {
}


//function to check whether or not a name exists in a list
//will return false if a name exists and true otherwise
template <typename T> bool check_names(list<SimpleList<T> *> l, string new_name) {

  for (auto itr : l) {

    if(itr->get_list_name().compare(new_name) == 0) {

      return false; 
    }
  }

  return true; 
}


//logic to retrieve a list that matches the parameter name
//will return the list if the name exists and null otherwise 
template <typename T> SimpleList<T> *get_list(list<SimpleList<T> *> l, string name) {

  for (auto itr : l) {

    if(itr->get_list_name().compare(name) == 0) {

      return itr; 
    }
  }
  return nullptr; 
}



//function to parse through the input file
void parse_file(string input_file, string output_file) {

  //ofstream and ifsteam objects to read and write from file
  ofstream of (output_file); 
  ifstream f  (input_file); 
  string line = ""; //stores content of a single line

  list<SimpleList<int> *> listSLi; // all integer stacks and queues
  list<SimpleList<double> *> listSLd; // all double stacks and queues
  list<SimpleList<string> *> listSLs; // all string stacks and queues

  //will only perform operations if the input file has successfully opened
  if(f.is_open()) {

    //while loop to run till the end of the file is reached
    while(!f.eof()) {

      //vector to store content of the line in words
      vector<string> buffer; 

      //gets content of line from file
      getline(f, line);
      if(line.empty()) { return; }

      //writes to output file current command
      of << "PROCESSING COMMAND: " << line << "\n"; 

      //logic to put words into buffer based on the command
      stringstream s(line);
      string itr = "";    
      while(s >> itr) {
        buffer.push_back(itr); 
      }

      //if the command is create or push it will have 3 words
      //otherwise if it's pop it will have two words
      string command = buffer[0], name = buffer[1], word = ""; 
      command.compare("pop") == 0 ? word = "" : word = buffer[2];  
      char type = name[0]; //variable that stores the list type (integer, double, string)


      //logic that creates stacks and queues based off of their type
      //will write to the output file an error if a list name already exists
      if(command.compare("create") == 0) {

        if(type == 'i') {

          if(!check_names(listSLi, name)) { of << "ERROR: This name already exists!" << "\n"; continue; } 
          listSLi.push_back(word.compare("stack") == 0 ?
            (SimpleList<int>*) new Stack<int>(name) : 
            (SimpleList<int>*) new Queue<int>(name));
        }
        if(type == 'd') {

          if(!check_names(listSLd, name)) { of << "ERROR: This name already exists!" << "\n"; continue; } 
          listSLd.push_back(word.compare("stack") == 0 ?
            (SimpleList<double>*) new Stack<double>(name) : 
            (SimpleList<double>*) new Queue<double>(name));
        }
        if(type == 's') {

          if(!check_names(listSLs, name)) { of << "ERROR: This name already exists!" << "\n"; continue; } 
          listSLs.push_back(word.compare("stack") == 0 ?
            (SimpleList<string>*) new Stack<string>(name) : 
            (SimpleList<string>*) new Queue<string>(name));
        }
      }

      //logic that pushes elements onto existing stacks and queues
      //will write to the output file an error if the name of a stack/queue doesn't exist
      if(command.compare("push") == 0) {

        if (type == 'i') {
          if (check_names(listSLi, name)) { of << "ERROR: This name does not exist!" << "\n"; continue; }
          get_list(listSLi, name)->push_list(stoi(word)); 
        }
        if (type == 'd') {

          if (check_names(listSLd, name)) { of << "ERROR: This name does not exist!" << "\n"; continue; }
          get_list(listSLd, name)->push_list(stod(word)); 
        }
        if (type == 's') {

          if (check_names(listSLs, name)) { of << "ERROR: This name does not exist!" << "\n"; continue; }
          get_list(listSLs, name)->push_list(word); 
        }
      }

      //logic that pops elements from existing stacks and queues
      //will write to the output file an error if the name of a stack/queue doesn't exist
      //will also write to the output file an error if a list is empty
      if(command.compare("pop") == 0) {

        if (type == 'i') {

          SimpleList<int> *my_list = get_list(listSLi, name); 
          if (check_names(listSLi, name)) { of << "ERROR: This name does not exist!" << "\n"; continue; }
          if (!my_list->get_list_size()) { of << "ERROR: This list is empty!" << "\n"; continue; }
          of << "Value popped: " << my_list->pop_list() << '\n';
        }
        if (type == 'd') {

          SimpleList<double> *my_list = get_list(listSLd, name); 
          if (check_names(listSLd, name)) { of << "ERROR: This name does not exist!" << "\n"; continue; }
          if (!my_list->get_list_size()) { of << "ERROR: This list is empty!" << "\n"; continue; }
          of << "Value popped: " << my_list->pop_list() << '\n';
        }
        if (type == 's') {

          SimpleList<string> *my_list = get_list(listSLs, name); 
          if (check_names(listSLs, name)) { of << "ERROR: This name does not exist!" << "\n"; continue; }
          if (!my_list->get_list_size()) { of << "ERROR: This list is empty!" << "\n"; continue; }
          of << "Value popped: " << my_list->pop_list() << '\n';
        }
      }
    } 
  }

  //closes output file
  of.close();
}
