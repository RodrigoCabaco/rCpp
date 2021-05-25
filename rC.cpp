#include "rInterpreter.h"
#include "common_functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
#define out cout
int main(int argc, char* argv[]){
    vector<string> strNames;
    vector<string> strValues;
    vector<string> code;
    if (argc >= 2) {
        for (size_t i = 1; i < argc; i++)
        {
            code = read_file(argv[i]);
            interpret(code, strNames, strValues);        
        }
    }else{
        try{

        }catch(const std::exception& e){

        }
    }
    return 0;
}