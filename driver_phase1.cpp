//Zhiyi Chen 10/7 Commit 1
#include <iostream>
#include "File.h"
//Gabriel Sencion 10/13/25 Commit 3
#include "Container.h"
using namespace std;

int main() {
    StringArray c;
    File::read("data.csv", c);

    //cout << "Data loaded from CSV: " << endl;
    c.print();

 

    return 0;
}

