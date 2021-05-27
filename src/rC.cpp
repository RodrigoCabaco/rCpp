#include "rInterpreter.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define out cout

vector<string> read_file(string filename)
{
    vector<string> final;
    try
    {
        string line;
        ifstream cpfile(filename);
        if (cpfile.is_open())
        {
            while (getline(cpfile, line))
            {
                final.push_back(line);
            }
            cpfile.close();
        }
    }
    catch (const std::exception &e)
    {
        throw invalid_argument("Error, could not open " + filename);
    }
    return final;
}

int main(int argc, char* argv[]){
    //basic definitions
    vector<string> strNames;
    vector<string> strValues;
    vector<string> code;
    vector<string> numberNames;
    vector<float> numberValues;
    vector<string> function_names;
    vector<vector<string>> function_content;
    string indent = "    ";
    if (argc >= 2) {
        for (size_t i = 1; i < argc; i++)
        {
            code = read_file(argv[i]);
            interpret(code, &strNames, &strValues, &numberNames, &numberValues,indent, &function_names, &function_content);
        }
    }else{
        try{
            code = read_file("Main.rcpp");
            interpret(code, &strNames, &strValues, &numberNames, &numberValues,indent, &function_names, &function_content);
        }catch(const std::exception& e){
        }
    }
    return 0;
}
