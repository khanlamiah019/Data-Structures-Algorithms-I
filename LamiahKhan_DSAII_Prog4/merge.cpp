/* Lamiah Khan DSA II, 11/27/2024 
   Any resources used will be linked to within the document. */
#include <fstream>
#include <iostream>
#include <string>

#define A 0
#define B 1
#define C 2
#define MAX_STRING_LENGTH 1001 

using namespace std;
// Approach: Solve the problem by using bottom-up dynamic programming; 
// reference: https://github.com/rabiulcste/dynamic-programming/blob/master/0-1%20Knapsack%20(Bottom%20Up).cpp

// Defining variables: 2D array to store dynamic programming states & function for merging logic
int strings[MAX_STRING_LENGTH][MAX_STRING_LENGTH] = {0};
string checkMerge(string *arrStrings);
// Array to hold the three input strings (A, B, C)
int main() {
    string arrStrings[3];
    string input, output;

    // Prompting user for input and output files
    cout << "Enter the name of the input file: ";
    cin >> input;
    ifstream inputFileStream(input.c_str());
    if(!inputFileStream){
        cerr << "ERROR: Could not open " << input << endl;
        exit(1);
    }
    cout << "Enter the name of the output file: ";
    cin >> output;
    // Opens output file for writing
    ofstream results(output.c_str());
    if(!results){
        cerr << "ERROR: Could not open " << output << endl;
        exit(1);
    }
    
    // Reads sets of three strings (A, B, C) from the input file and processes each. Then calls checkMerge and writes results
    while(getline(inputFileStream, arrStrings[A]) && getline(inputFileStream, arrStrings[B]) && getline(inputFileStream, arrStrings[C])){
        results << checkMerge(arrStrings) << endl;
    }
    inputFileStream.close();
    results.close();

    return 0;
}
// Function to verify if C is a valid merge of A and B.
string checkMerge(string *arrStrings){
    int lengths[3] = {arrStrings[A].length(), arrStrings[B].length(), arrStrings[C].length()};

    // Checks if the length of C matches the combined length of A and B. If not, not a valid merge
    if((lengths[A] + lengths[B]) != lengths[C]){
        return "*** NOT A MERGE ***";
    }

    // Initializes 2D DP table to track possible merges. 
    for(int i = 0; i < MAX_STRING_LENGTH; i++){
        for(int j = 0; j < MAX_STRING_LENGTH; j++){
            strings[i][j] = 0;
        }
    }
    // Base case: an empty prefix of A and B can merge to an empty prefix of C.
    strings[0][0] = 1;

    // Fill the DP table using bottom-up approach.
    // Link to reference code: https://gist.github.com/u8989332/adece58244339e54d8b16f7a3dd14143
    for(int i = 0; i <= lengths[A]; i++){
        for (int j = 0; j <= lengths[B]; j++){
            if(strings[i][j] == 0){
                continue;   // skip if position is not reachable
            }
            // Checks if next character in A matches current position in C, and if yes, marks as reachable.
            if(arrStrings[C][i+j] == arrStrings[A][i]){
                strings[i+1][j] = 1;
            }
            // Does the same as above but checks B and C.
            if(arrStrings[C][i+j] == arrStrings[B][j]){
                strings[i][j+1] = 1;
            }
        }
        
    }
    // If bottom-right corner of DP table is not reachable, return not a merge
    if(strings[lengths[A]][lengths[B]] == 0){
        return "*** NOT A MERGE ***";
    }

    // Traverse backwards through DP table to construct final merged string with case modifications
    // If current character in C comes from A, convert to uppercase
    // Else: assume character is from B, convert to lowercase
    // link: https://stackoverflow.com/questions/6297568/jquery-if-a-length-0-b-length-1-do-something
    while(lengths[A] > 0 && lengths[B] >= 0){
        if(strings[lengths[A]][lengths[B]] == 1 && (lengths[B] == 0 || strings[lengths[A]][lengths[B]-1] == 0)){
            arrStrings[C][lengths[A]+lengths[B]-1] = arrStrings[C][lengths[A]+lengths[B]-1] & ~32;
            lengths[A]--;
        }else{
            arrStrings[C][lengths[A]+lengths[B]-1] = arrStrings[C][lengths[A]+lengths[B]-1] | 32;
            lengths[B]--;
        }
    }

    return arrStrings[C]; // Returns modified C as valid merge
}
