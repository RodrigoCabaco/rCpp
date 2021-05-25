#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
#define out cout
vector<string> list_split(string initial, string delimitator){
    vector<string> final;
    int s1 = initial.size()+1;
    int s2 = delimitator.size()+1;
    char* _initial = new char [s1];
    char* _delimitator = new char[s2];
    strcpy(_initial, initial.c_str());
    strcpy(_delimitator, delimitator.c_str());
    char *token = strtok(_initial,_delimitator);
    while (token)
    {   
        final.push_back(token);
        token = strtok(NULL,_delimitator);
    }
    delete[] _initial;
    delete[] _delimitator;
    return final;
}


bool StartsWith(string str, string to_check){
    if (str.rfind(to_check,0)==0){
        return true;
    }else{
        return false;
    }
}