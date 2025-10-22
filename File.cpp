// Zhiyi Chen 10/7 Commit 1
#include "File.h"
// Gabriel Sencion 10/13/25 Commit 3
#include "Container.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

// Gabriel Sencion 10/15/25 fixed while statement to read and output data.csv
// Updated by Giankarlo Gomez 10/21/25: removed printing, fixed to load data into container

void File::read(const std::string& filename, StringArray& stringArray) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {                 // read each line
        stringstream ss(line);
        string value;

        while (getline(ss, value, ',')) {         // split by commas
            // remove leading spaces if any
            if (!value.empty() && value[0] == ' ')
                value = value.substr(1);

            stringArray.push_back(value);         // store value into array
        }
    }

    file.close();
}
