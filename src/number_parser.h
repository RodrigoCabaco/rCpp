#include <string>
#include <iostream>
using namespace std;

float parse_num(string* num){
    float final_val = std::stof(*num);
    return final_val;
}