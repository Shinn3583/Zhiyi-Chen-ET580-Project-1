//Zhiyi Chen 10/7 Commit 1
//Phase 2, cp driver_phase1.cpp into cp driver_phase2.cpp

#include <iostream>
#include "File.h"
//Gabriel Sencion 10/13/25 Commit 3
#include "Container.h"
using namespace std;
int main()
{
    StringArray c;
    File::read("data.csv", c);
    //cout << "Data loaded from CSV: " << endl;
    c.print();
    // ==================================================
    // Giankarlo Gomez 10/21/25 - Phase 2 Implementation
    // Added sorting and searching tests according to Group A instructions
    // ==================================================
    cout << endl << "=== Testing selectionSortAsc() ===" << endl;
    c.selectionSortAsc();
    c.print();
    cout << endl << "=== Testing linearSearch() ===" << endl;
    string key1 = "70";
    string key2 = "25";
    cout << "Searching for " << key1 << ": " << c.linearSearch(key1) << endl;
    cout << "Searching for " << key2 << ": " << c.linearSearch(key2) << endl;
    cout << endl << "=== Testing binarySearch() ===" << endl;
    cout << "Searching for " << key2 << ": " << c.binarySearch(key2) << endl;
    // ===============================================
    // Phase 2 tests - Group A (Giankarlo Gomez)
    // ===============================================
    cout << endl << "=== Testing at(), insert(), erase(), pop_back(), resize() ===" << endl;
    // at()
    cout << "at(0): " << c.at(0) << endl;
    // insert at middle (index 3 for example)
    c.insert(3, "INSERTED");
    c.print();
    // erase the same position
    c.erase(3);
    c.print();
    // pop_back on non-empty
    c.pop_back();
    c.print();
    // resize smaller (shrink)
    c.resize(5);
    c.print();
    // resize larger (fills with "")
    c.resize(8);
    c.print();
    cout << endl << "=== Program finished successfully ===" << endl;
    return 0;
    }

 




