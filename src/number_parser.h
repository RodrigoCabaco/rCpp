#include <string>
#include <iostream>
#include <sstream>
using namespace std;
string num_to_str(float num){
    std::stringstream ss1;
    ss1 << num;
    std::string str1 = ss1.str();
    return str1;
}
float parse_num(string* num){
    float final_val = std::stof(*num);
    return final_val;
}