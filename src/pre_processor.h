#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//escape codes
string escape_codes_typed [] = {"\\n","\\\""};
string escape_codes [] = {"\n","\"" };

string numStr_process(float num){
    std::stringstream ss1;
    ss1 << num;
    std::string str1 = ss1.str();
    return str1;
}



string pre_process(string *_line, vector<string> strNames,
vector<string> strValues, 
vector<string> numberNames, 
vector<float> numberValues){
	string line = *_line;
    for(auto escape:escape_codes_typed){
		if (line.find(escape)!=std::string::npos){
			line.replace(line.find(escape), escape.size(), escape_codes[escape_codes_typed->find(escape)]);
		}
	}
	// if(StartsWith(line, "}")){
	// 	line = remove_spaces(line);
	// }
	// if(StartsWith(line, "{")){
	// 	line = remove_spaces(line);
	// }
	if (line.find("$")!=string::npos){
		for (size_t i = 0; i < strNames.size(); i++)
		{	
			if(line.find("$"+strNames[i]+"$")!=string::npos){
				while(line.find("$"+strNames[i]+"$")!=string::npos){
					line.replace(line.find("$"+strNames[i]+"$"), ("$"+strNames[i]+"$").size(), strValues[i]);
				}
			}	
		}
		for (size_t i = 0; i < numberNames.size(); i++)
		{
			if(line.find("$"+numberNames[i]+"$")!=string::npos){
				while(line.find("$"+numberNames[i]+"$")!=string::npos){
					line.replace(line.find("$"+numberNames[i]+"$"), ("$"+numberNames[i]+"$").size(), numStr_process(numberValues[i]));}
			}	
		}
	}
	
	return line;
};
