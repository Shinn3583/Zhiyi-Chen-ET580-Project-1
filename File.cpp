//Zhiyi Chen 10/7 Commit 1
#include "File.h"
//Gabriel Sencion 10/13/25 Commit 3
#include "Container.h"
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

void File::read(const std::string& filename, StringArray& StringArray) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }
 
 
std::string line;
if (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string value;
    while (std::getline(ss, value, ',')) {
        StringArray.maxSize();
    }
}


file.close();
}
