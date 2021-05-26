#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;
#define out cout
vector<string> list_split(string initial, string delimiter){
    vector<string> tokens;
    char str[initial.size()+1];
    char _delimiter[delimiter.size()+1];
    strcpy(str, initial.c_str());
    strcpy(_delimiter, delimiter.c_str());
    char *token = strtok(str, _delimiter);
  
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {

       tokens.push_back(token);
        token = strtok(NULL, _delimiter);

    }
    return tokens;
  
}


bool StartsWith(string str, string to_check){
    if (str.rfind(to_check,0)==0){
        return true;
    }else{
        return false;
    }
}