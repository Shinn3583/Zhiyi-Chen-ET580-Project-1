//Zhiyi Chen 10/7 Commit 1
#include "Container.h"

//Zhiyi Chen 10/13 Commit 2
StringArray::StringArray(int initialMax) : maxValues(initialMax), numValues(0) 
{
    data = new std::string[maxValues];
}

// Destructor
StringArray::~StringArray() 
{
    delete[] data;
}

//grow the array

void StringArray::growArray(int newMax) 
{
    std::string* newData = new std::string[newMax];
    
    //copy existing data
    for (size_t i = 0; i < numValues; ++i) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
    maxValues = newMax;
}

// check if array is empty

bool StringArray::empty()
{
    return numValues == 0;
}

// return current number of values
int StringArray::size()
{
    return numValues;
}

// return maximum value 
int StringArray::maxSize()
{
    return maxValues;
}

// Reserve capacity
void StringArray::reserve(int n) 
{
    if (n > maxValues) {
        growArray(n);
    }
}

//reset to default

void StringArray::clear() 
{
    delete[] data;
    maxValues = 5;
    numValues = 0;
    data = new std::string[maxValues];
}

// Add value to the end of array
void StringArray::push_back(std::string& value) 
{
    if (numValues == maxValues) {
        growArray(maxValues * 2); // Double the capacity
    }
    data[numValues] = value;
    numValues++;
}

// Print all values
void StringArray::print()
{
    for (int i = 0; i < numValues; ++i) {
        std::cout << data[i];
        if (i < numValues - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}