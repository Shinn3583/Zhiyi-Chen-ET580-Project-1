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
    // Searching and sorting (Phase 2) Giankarlo Gomez 10/21/25
    int linearSearch(std::string target);    // returns index or -1
    void selectionSortAsc();                 // sort ascending (numeric)
    int binarySearch(std::string target);    // requires sorted asc
    bool empty();
    int size();
    int maxSize();
    void reserve(int n);
    void clear();
    void push_back(std::string& value);
    void print();
    std::string& at(int index);         // read/write access with assert
    void resize(int n);                 // change current number of values
    void pop_back();                    // remove last value (if any)
    void insert(int index, const std::string& value);  // insert value at index
    void erase(int index);              // erase value at index
};
#endif