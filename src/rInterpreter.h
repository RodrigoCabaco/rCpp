#include "common_functions.h"
#include <iostream>
#include "parser.cpp"
#include <vector>
#include "Errors.h"
#include <string>
#include <algorithm>
using namespace std;

// parser.parse returnes a keyword which is then further processed
// Keywords: Write, str_declare, num_declare, WriteStr, WriteNum, for_loop, if_statement, while_loop, etc.
void interpret(vector<string> code,vector<string> strNames,vector<string> strValues) {

	//escape codes
	string escape_codes_typed [] = {"\\n","\\\""};
	string escape_codes [] = {"\n","\"" };
	//store variables
	for (size_t i = 0; i < code.size(); i++)
	{
		try {
			string *ptr_line = &code[i];
			string line = *ptr_line;
			//Basic Write Method: Write("Something")
			string keyword = parse(&line);
			//Write
			for(auto escape:escape_codes_typed){
				if (line.find(escape)!=std::string::npos){
					line.replace(line.find(escape), escape.size(), escape_codes[escape_codes_typed->find(escape)]);
				}
			}
			if (keyword == "write"){
				string to_out = get_tokens(get_tokens(get_tokens(line, "Write")[1],"(\"")[1],"\")")[0];
				cout << to_out;
				continue;
			}
			else if (keyword == "str_declare"){
				//str i = "123"
				string name = get_tokens(get_tokens(line, "str ")[1], " ")[0];
				string value = get_tokens(
					get_tokens(
						get_tokens(
							get_tokens(
								line, "str "+name)[1], "=")[1],
								"\"")[1], "\"")[0];
				
				//string value = get_tokens(line, get_tokens("="))
				
				strNames.push_back(name);
				strValues.push_back(value);
				continue;
			}
		}catch(std::exception &e){
			cout << "Error on line " << i+1 << " -> "<< code[i] << " <-\n";
			exit(1);
		}
	}
	
}