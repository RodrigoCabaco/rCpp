#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//escape codes
string escape_codes_typed [] = {"\\n","\\\""};
string escape_codes [] = {"\n","\"" };

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
				while(line.find("$"+strNames[i]+"$")!=string::npos)
					line.replace(line.find("$"+strNames[i]+"$"), strNames.size()+1, strValues[i]);
			}	
		}
		
	}
	
	return line;
};