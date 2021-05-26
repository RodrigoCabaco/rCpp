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
	//store variables
	for (size_t i = 0; i < code.size(); i++)
	{
		string *ptr_line = &code[i];
		string line = *ptr_line;
		//Basic Write Method: Write("Something")
		string keyword = parse(&line);
		//Write
		if (keyword == "write"){
			string to_out = split(split(split(line, "Write")[1],"(\"")[1],"\")")[0];
			cout << to_out;
		}
		else if (keyword == "str_declare"){
			string to_out = split(split(split(line, "Write")[1],"(\"")[1],"\")")[0];
			cout << to_out;
		}
	}
	
}