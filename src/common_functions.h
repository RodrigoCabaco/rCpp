#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;
#define out cout

int getIndexStr(vector<string> v, string K)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if(v[i]==K)
            return i;
    }
    return -1;
}

string remove_str_next(string str, string to_remove){
    return str.substr(str.find(to_remove)+to_remove.size(), str.size()-1);
}

string remove_str_first(string str, string to_remove){
    return str.substr(0, str.find(to_remove)+to_remove.size());
}
vector<string> get_tokens(string str, string delimiter){
    vector<string> final;
    if (str.find(delimiter)!=string::npos){
        final.push_back(str.substr(0,str.find(delimiter)));
    }else{
        final.push_back(str);
    }
    int current;
    while (str.find(delimiter) != string::npos) {
        int pos = str.find(delimiter);
        // 4
        str = str.substr(pos+delimiter.size());
        current++;
        final.push_back(str);
    } 
    final.push_back("");
    return final;
}


bool StartsWith(string str, string to_check){
    if (str.rfind(to_check,0)==0){
        return true;
    }else{
        return false;
    }
}