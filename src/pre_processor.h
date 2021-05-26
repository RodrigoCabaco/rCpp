#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//escape codes
string escape_codes_typed [] = {"\\n","\\\""};
string escape_codes [] = {"\n","\"" };

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        size_t end_pos = start_pos + from.length();
        str.replace(start_pos, end_pos, to);
        start_pos += to.length();
    }
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
	if (line.find("$")!=string::npos){
		for (size_t i = 0; i < strNames.size(); i++)
		{
			if(line.find("$"+strNames[i]+"$")!=string::npos){
				replaceAll(line, "$"+strNames[i]+"$", strValues[i]);
			}	
		}
		for (size_t i = 0; i < numberNames.size(); i++)
		{
			if(line.find("$"+numberNames[i]+"$")!=string::npos){
				replaceAll(line, "$"+numberNames[i]+"$", to_string(numberValues[i]));
			}	
		}
	}
	
	return line;
};