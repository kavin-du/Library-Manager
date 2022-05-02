#include "headers.h"

#include <iostream>
#include <string>

using namespace std;

// implementation of the class Entry
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
  cout << "Name: " << this->name \
      << "\nYear: " << this->year \
      << "\nBorrowed: " << (this->borrowed ? "Yes" : "No") \
      << (this->borrowed ? "\nBorrowed by: " : "") << this->borrowedBy \
      << "\n\n";
}


// implementation of the class MusicAlbum
MusicAlbum::MusicAlbum(
  string name, 
  string year,
  bool borrowed,
  string borrowedBy, 
  string artist, 
  string recordLabel
) : Entry(name, year, borrowed, borrowedBy) {
  this->artist = artist;
  this->recordLabel = recordLabel;
};

// overriding the print function
void MusicAlbum::printDetails() {
  cout << "Name: " << this->name \
      << "\nYear: " << this->year \
      << "\nBorrowed: " << (this->borrowed ? "Yes" : "No") \
      << (this->borrowed ? "\nBorrowed by: " : "") << this->borrowedBy \
      << "\nArtist: " << this->artist \
      << "\nRecord Label: " << this->recordLabel \
      << "\n\n";
}