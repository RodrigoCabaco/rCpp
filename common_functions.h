#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
vector<string> read_file(string filename)
{
    vector<string> final;
    try
    {
        string line;
        ifstream cpfile(filename);
        if (cpfile.is_open())
        {
            while (getline(cpfile, line))
            {
                final.push_back(line);
            }
            cpfile.close();
        }
    }
    catch (const std::exception &e)
    {
        throw invalid_argument("Error, could not open " + filename);
    }
    return final;
}
