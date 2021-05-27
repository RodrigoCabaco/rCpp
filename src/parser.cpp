#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> keywords= {
"write",//done
"write",//done
"str_declare",//done
"num_declare",//done
"write_str",//done
"write_num",//done
"comment",//done
"write_line", //done
"write_line", //done
"++",
"--",
"for_loop",
"}",
"{",
"function_declare"};
vector<string> keywords_typed = {
"Write ",//done
"Write(", //done
"str ",//done
"num ",//done
"WriteStr",//done
"WriteNum", //done
"//",//done
"WriteLine ",//done
"WriteLine("//done
, "++"
, "--",
"for "
,"}",
"{",
"function "};

string parse(string *ptr_line, vector<string> exceptions){
    for (size_t i = 0; i < exceptions.size(); i++)
    {
        keywords_typed.push_back(exceptions[i]);
        keywords.push_back(exceptions[i]);
    }
    
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
        bool is_exception = false;
        for (size_t i = 0; i < exceptions.size(); i++)
        {
            if(StartsWith(np_line, exceptions[i])){
                is_exception = true;
            }
        }
        if(is_exception==false){
            cout << "Unknown token \""<<get_tokens(np_line, " ")[0] <<"\"\n";
        }
        exit(1);
    }
        
    
    return parsed;
}
