// Ruoming Ye 10/26/25 create Algorithms.cpp for Phase 3
#include <iostream>
#include <cassert>
#include "Algorithms.h"

using namespace std;

// rotate(): shift elements left or right by n positions
void rotate(StringArray& data, int n){
    int size = data.size();
    if (size == 0) return;

    n = n % size;
    if (n < 0) n += size;

    StringArray box;
    box.reserve(size);
    box.resize(size);

    for (int i = 0; i < size; ++i){
        box.at((i + n) % size) = data.at(i);
    }
    // copy rotated result back
    for (int i = 0; i < size; ++i){
        data.at(i) = box.at(i);
    }
}

// isRotated(): check if A is a rotated version of B
bool isRotated(StringArray& A, StringArray& B){
    if(A.size() != B.size()) return false;
    
    int size = A.size();
    if(size == 0) return true;

    for(int shift = 0; shift < size; ++shift){
        bool match = true;
        for(int i = 0; i < size; ++i){
            if(A.at(i) != B.at((i + shift) % size)){
                match = false;
                break;
            }
        }
        if(match) return true;
    }
    return false;
}

