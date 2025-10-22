// Zhiyi Chen 10/7 Commit 1
#include "Container.h"
#include <iostream>
#include <cassert>
using namespace std;

// Gabriel Sencion 10/14/25 Commit 2
// Updated by Giankarlo Gomez: formatted to professor’s instructions

// ======================================
// Default constructor
// ======================================
StringArray::StringArray(int initialMax)
{
    assert(initialMax > 0);
    maxValues = initialMax;                  // maximum number of values
    numValues = 0;                           // current number of values
    data = new string[maxValues];            // allocate memory
}

// ======================================
// Destructor
// ======================================
StringArray::~StringArray()
{
    delete [] data;                          // free allocated memory
}

// ======================================
// grow the array (private helper)
// ======================================
void StringArray::growArray(int newMax)
{
    assert(newMax >= numValues);             // make sure new size fits current data
    string* tmp = new string[newMax];

    for (int i = 0; i < numValues; ++i)
        tmp[i] = data[i];

    delete [] data;
    data = tmp;
    maxValues = newMax;
}

// ======================================
// Core member functions
// ======================================
bool StringArray::empty()
{
    return numValues == 0;
}

int StringArray::size()
{
    return numValues;
}

int StringArray::maxSize()
{
    return maxValues;
}

void StringArray::reserve(int n)
{
    if (n > maxValues)
        growArray(n);
}

void StringArray::clear()
{
    numValues = 0;                           // clear values but keep memory
}

void StringArray::push_back(string& value)
{
    if (numValues == maxValues)
        growArray(maxValues * 2);

    data[numValues++] = value;
}

// ======================================
// Print (output contents of array)
// ======================================
void StringArray::print()
{
    if (numValues == 0)
    {
        cout << "(empty)" << endl;
        return;
    }

    for (int i = 0; i < numValues; ++i)
    {
        cout << data[i];
        if (i + 1 < numValues)
            cout << ", ";
    }
    cout << endl;
}
// ======================================
// Linear Search (returns index or -1) Phase2 Giankarlo Gomez 10/21/25
// ======================================
int StringArray::linearSearch(std::string target)
{
    for (int i = 0; i < numValues; ++i)
    {
        // numeric compare: convert both sides with stoi G.G
        if (stoi(data[i]) == stoi(target))
            return i;
    }
    return -1;
}

// ======================================
// Selection Sort Ascending (numeric) G.G
// ======================================
void StringArray::selectionSortAsc()
{
    for (int i = 0; i < numValues - 1; ++i)
    {
        int minPos = i;
        for (int j = i + 1; j < numValues; ++j)
        {
            if (stoi(data[j]) < stoi(data[minPos]))
                minPos = j;
        }

        if (minPos != i)
        {
            // swap
            std::string t = data[i];
            data[i] = data[minPos];
            data[minPos] = t;
        }
    }
}

// ======================================
// Binary Search (array must be sorted asc) G.G
// Returns index or -1
// ======================================
int StringArray::binarySearch(std::string target)
{
    int key = stoi(target);
    int low = 0;
    int high = numValues - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midVal = stoi(data[mid]);

        if (key == midVal)
            return mid;
        else if (key < midVal)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
