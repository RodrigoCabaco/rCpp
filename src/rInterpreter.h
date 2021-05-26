#include "common_functions.h"
#include "pre_processor.h"
#include "parser.cpp"
#include "Errors.h"
#include "number_parser.h"


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


// parser.parse returnes a keyword which is then further processed
// Keywords: Write, str_declare, num_declare, WriteStr, WriteNum, for_loop, if_statement, while_loop, etc.
void interpret(
vector<string> code,
vector<string> strNames,
vector<string> strValues, 
vector<string> numberNames, 
vector<float> numberValues) {

	
	//store variables
	for (size_t i = 0; i < code.size(); i++)
	{
		try {

			string *ptr_line = &code[i];
			string line = *ptr_line;
			//Basic Write Method: Write("Something")
			string keyword = parse(&line);
			//Write
			line = pre_process(&line, strNames, strValues, numberNames, numberValues);
			if (keyword == "write"){
				string to_out = get_tokens(get_tokens(get_tokens(line, "Write")[1],"(\"")[1],"\")")[0];
				cout << to_out;
				continue;
			}else if(keyword=="write_line"){
				string to_out = get_tokens(get_tokens(get_tokens(line, "WriteLine")[1],"(\"")[1],"\")")[0];
				cout << to_out<<endl;
				continue;
			}
			else if (keyword == "str_declare"){
				//str i = "123"
				string name = get_tokens(get_tokens(line, "str ")[1], " ")[0];
				string value = "";
				if (line.find("\"")!=string::npos){
				value = get_tokens(
					get_tokens(
						get_tokens(
							get_tokens(
								line, "str "+name)[1], "=")[1],
								"\"")[1], "\"")[0];
				}
				
				strNames.push_back(name);
				strValues.push_back(value);
				continue;
			}else if (keyword=="num_declare"){
				string name = get_tokens(get_tokens(line, "str ")[1], " ")[0];
				string unparsed_value = get_tokens(get_tokens(line, "num "+name)[1],"=")[1];
				string str = unparsed_value;
				str.erase(remove(str.begin(), str.end(), ' '), str.end());
				numberNames.push_back(name);
				numberValues.push_back(parse_num(&str));
			}
		}catch(std::exception &e){
			cout << "Error on line " << i+1 << " -> "<< code[i] << " <-\n";
			exit(1);
		}
	}
	
}