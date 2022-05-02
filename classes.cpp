#include "headers.h"

#include <iostream>
#include <string>

using namespace std;

// definitions of class Entry
Entry::Entry(string name, string year,bool borrowed,string borrowedBy) {
  this->name = name;
  this->year = year;
  this->borrowed = borrowed;
  this->borrowedBy = borrowedBy;
};

// when an item is borrowed add the name 
// make borrowed to true
void Entry::entryBorrowed(string name) {
  this->borrowedBy = name;
  this->borrowed = true;
}

// make the flag false after item is returned
void Entry::entryReturned() {
  this->borrowed = false;
  this->borrowedBy = "";
}

void Entry::printDetails() {
  cout << "name: " << this->name \
      << "\nyear: " << this->year \
      << "\nborrowed: " << (this->borrowed ? "Yes" : "No") \
      << "\nborrowedBy: " << this->borrowedBy \
      << endl;
}