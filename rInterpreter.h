#include "common_functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void interpret(vector<string> code,vector<string> strNames,vector<string> strValues) {
	//store variables
	for (size_t i = 0; i < code.size(); i++)
	{
		string *ptr_line = &code[i];
		string line = *ptr_line;
		//Basic Write Method: Write("Something")
		if (StartsWith(*ptr_line,"Write(")|| StartsWith(*ptr_line,"Write (")){
			//Write ("")
			if(StartsWith(line, "Write (\"")){
				string to_out = list_split(line, "Write (\"")[1];
				//cout << to_out;
			}else if(StartsWith(line, "Write(\"")){
				string to_out = list_split(list_split(line, "Write(\"")[1], "\")")[0];
				cout << to_out;
			}
		}
	}
	
}