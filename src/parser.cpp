#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string keywords []= {"write","write","str_declare",
"num_declare","write_str","write_num"};
string keywords_typed [] = {"Write ","Write(", "str ", 
"num ","WriteStr","WriteNum"};

string parse(string *ptr_line){
    string parsed = "";
    string np_line = *ptr_line;
    for (size_t i = 0; i < keywords_typed->size(); i++)
    {
        if (StartsWith(np_line, keywords_typed[i])){
            string parsed = keywords[i];
            return parsed;
        }else{
            if (StartsWith(np_line,"//")==false){
                cout << "Unknown token \""<<get_tokens(np_line, " ")[0] << "\" at line "<<i+1;
                exit(1);
            }
        }
    }
    
    return parsed;
}