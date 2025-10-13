//Zhiyi Chen 10/7 Commit 1
#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
//Zhiyi Chen 10/13 Commit 2
class StringArray {
private:
    int maxValues;    //maximum number of values
    int numValues;    // Current number of values
    std::string* data; 

    //grow the array
    void growArray(int newMax);

public:
    // Constructor
    StringArray(int initialMax = 5);
    
    // Destructor
    ~StringArray();
    
    // Core member functions
    bool empty();
    int size();
    int maxSize();
    void reserve(int n);
    void clear();
    void push_back(std::string& value);
    void print();
};
#endif