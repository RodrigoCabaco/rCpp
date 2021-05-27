#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void type_error(string causer, string explanation){
    cout << "Type Error: " << causer <<" -> \""<< explanation<<"\""<<endl;
}