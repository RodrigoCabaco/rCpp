#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> keywords= {"write","write","str_declare","num_declare","write_str","write_num", "comment","write_line", "write_line"};
vector<string> keywords_typed = {"Write ","Write(", "str ", "num ","WriteStr","WriteNum", "//", "WriteLine ", "WriteLine("};

string parse(string *ptr_line){
    string parsed = "";
    string np_line = *ptr_line;
    int f = 0;
    for (size_t i = 0; i < keywords_typed.size(); i++)
    {
        if (StartsWith(np_line, keywords_typed[i]) && np_line!="" && np_line!=" "&&StartsWith(np_line," ")==false){
            parsed = keywords[i];
            return parsed;
        }
    }
    if (parsed==""&&np_line!=""&&StartsWith(np_line, " ")==false&&StartsWith(np_line, "\n")==false){
        cout << "Unknown token \""<<get_tokens(np_line, " ")[0] <<"\"\n";
        exit(1);
    }
        
    
    return parsed;
}