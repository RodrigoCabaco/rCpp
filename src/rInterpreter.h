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


int getIndexStr(vector<string> v, string K) 
{ 
    auto it = find(v.begin(), v.end(), K); 
  
    if (it != v.end()) { 

        int index = distance(v.begin(), it); 
        return index;
    } 
    else { 
        return -1;
    } 
} 

string remove_spaces(string _str){
	string str = _str;
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}



// parser.parse returns a keyword which is then further processed
// Keywords: Write, str_declare, num_declare, WriteStr, WriteNum, for_loop, if_statement, while_loop, etc.
void interpret(
vector<string> code,
vector<string> strNames,
vector<string> strValues, 
vector<string> numberNames, 
vector<float> numberValues,
string indent) {

	
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
				string name = get_tokens(get_tokens(line, "str ")[1], " ")[0];
				string value = "";
				string parsed__ = get_tokens(
							get_tokens(
								line, "str "+name)[1], "=")[1];
				parsed__ = remove_spaces(parsed__);
				if(parsed__!="readline()"){
				
					if (line.find("\"")!=string::npos){
					value = get_tokens(
						get_tokens(
							get_tokens(
								get_tokens(
									line, "str "+name)[1], "=")[1],
									"\"")[1], "\"")[0];
					}
						int index = getIndexStr(strNames, name);
					if(index==-1){
						strNames.push_back(name);
						strValues.push_back(value);
					}else{
						strValues[index] = value;
					}
				}else{
					string to_add;
					try{
						cin >> to_add;
						unsigned int index = getIndexStr(strNames, name);
						if(index==-1){
							strNames.push_back(name);
							strValues.push_back(to_add);
						}else{
							strValues[index] = to_add;
						}
					}catch(std::exception &e){
						type_error("readline()", "failed to read correct input");
					}
				}
				
				
				continue;
			}else if (keyword=="num_declare"){
				string name = get_tokens(get_tokens(line, "num ")[1], " ")[0];
				string unparsed_value = get_tokens(get_tokens(line, "num "+name)[1],"=")[1];
				string parsed__ =  get_tokens(get_tokens(line, "num "+name)[1],"=")[1];
				parsed__.erase(remove(parsed__.begin(), parsed__.end(), ' '), parsed__.end());
				if (parsed__!="readline()"){
					string str = unparsed_value;
					str.erase(remove(str.begin(), str.end(), ' '), str.end());
					for (size_t i = 0; i < numberNames.size(); i++)
					{
						if (str.find(numberNames[i])!=string::npos){
							while(str.find(numberNames[i])!=string::npos){
								str.replace(str.find(numberNames[i]),numberNames[i].size(), numStr_process(numberValues[i]));
							}
						}
					}
					unsigned int index = getIndexStr(numberNames, name);
					if(index==-1){
						numberNames.push_back(name);
						numberValues.push_back(parse_num(&str));
					}else{
						numberValues[index] = parse_num(&str);
					}
				}else{
					float to_add;
					try{
						cin >> to_add;
						unsigned int index = getIndexStr(numberNames, name);
						if(index==-1){
							numberNames.push_back(name);
							numberValues.push_back(to_add);
						}else{
							numberValues[index] = to_add;
						}
					}catch(std::exception &e){
						type_error("readline()", "failed to read correct input");
					}
				}
			}else if(keyword=="write_num"){
				string to_parse = get_tokens(get_tokens(get_tokens(line, "WriteNum")[1], "{")[1],"}")[0];
				char* _to_parse = new char[to_parse.size()+1];
				strcpy(_to_parse, to_parse.c_str());
				char *token = strtok(_to_parse, ","); 
				vector<string> parsed;

				while (token != NULL) 
				{ 
					parsed.push_back(token);
					token = strtok(NULL, ","); 
				}
				for (auto __parsed_token:parsed){
					__parsed_token.erase(remove(__parsed_token.begin(), __parsed_token.end(), ' '), __parsed_token.end());
					if(getIndexStr(numberNames, __parsed_token)!=-1){
						cout << numberValues[getIndexStr(numberNames, __parsed_token)];
					}else{
						type_error(__parsed_token, "variable does not exist");
						exit(1);
					}
				}
			}
			else if(keyword=="write_str"){
				string to_parse = get_tokens(get_tokens(get_tokens(line, "WriteStr")[1], "{")[1],"}")[0];
				char* _to_parse = new char[to_parse.size()+1];
				strcpy(_to_parse, to_parse.c_str());
				char *token = strtok(_to_parse, ","); 
				vector<string> parsed;
				

				while (token != NULL) 
				{ 
					parsed.push_back(token);
					token = strtok(NULL, ","); 
				}
				for (auto __parsed_token:parsed){
					__parsed_token.erase(remove(__parsed_token.begin(), __parsed_token.end(), ' '), __parsed_token.end());
					if(getIndexStr(strNames, __parsed_token)!=-1){
						cout << strValues[getIndexStr(strNames, __parsed_token)];
					}else{
						type_error(__parsed_token, "variable does not exist");
						exit(1);
					}
				}
			}else if(keyword == "for_loop"){
				//for i in range:100;
				if(line.find(" in range:")!=std::string::npos)
				{
					string _iterator = get_tokens(get_tokens(line, "for ")[1], " in range:")[0];
					string get_range =  get_tokens(get_tokens(get_tokens(line, "for ")[1], " in range:")[1], ";")[0];
					int range;
					if (getIndexStr(numberNames, get_range)==-1){
						range = std::stoi(get_range);
					}else{
						range = numberValues[getIndexStr(numberNames, get_range)];
					}
					vector<string> to_compile_ = {code.begin()+i+1, code.end()};
					vector<string> to_compile = {to_compile_.begin(), to_compile_.begin()+(getIndexStr(to_compile_, "}"))};
					//purify
					for (size_t _i = 0; _i < to_compile.size(); _i++)
					{
						string _line = to_compile[_i];
						if (StartsWith(_line, indent)){
							to_compile[_i] = get_tokens(_line, indent)[1]; 
						}
					}
					numberNames.push_back(_iterator);
					numberValues.push_back(0);
					for (size_t __i = 0; __i < range; __i++)
					{
						numberValues[getIndexStr(numberNames, _iterator)] = __i;
						interpret(to_compile, strNames, strValues, numberNames, numberValues,indent);
					}
	

				}else{
					type_error("for_loop", "Wrong syntax, correct -> for i in range:x;");
				}
				
			}
		}catch(std::exception &e){
			cout << "Error on line " << i+1 << " -> "<< code[i] << " <-\n";
			exit(1);
		}
	}
	
}

