//Zhiyi Chen 10/7 Commit 1
#include "File.h"
//Gabriel Sencion 10/13/25 Commit 3
#include "Container.h"
#include <fstream>
#include <sstream>
#include<string>
using namespace std;
//Gabriel Sencion 10/15/25 fixed while statment to read and output data.csv

void File::read(const std::string& filename, StringArray& stringArray) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
 
cout << "Data loaded from CSV: " << endl;   // print header first
 
string line;
while (getline(file, line)) {                //read each line
    stringstream ss(line);
    string value;

    while (getline(ss, value, ',')) {       //split byt commas
        cout << value << " ";               //prints each number 
    }
    cout << endl;                           //new line after each row
}

file.close();
}
