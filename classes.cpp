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


// implementation of the class Book
Book::Book(
  string name, 
  string year,
  bool borrowed,
  string borrowedBy, 
  string author, 
  string publisher,
  string edition
) : Entry(name, year, borrowed, borrowedBy) {

  this->author = author;
  this->publisher = publisher;
  this->edition = edition;
};

// overriding the print function
void Book::printDetails() {
  cout << "Name: " << this->name \
      << "\nYear: " << this->year \
      << "\nBorrowed: " << (this->borrowed ? "Yes" : "No") \
      << (this->borrowed ? "\nBorrowed by: " : "") << this->borrowedBy \
      << "\nAuthor: " << this->author \
      << "\nPublisher: " << this->publisher \
      << "\nEdition: " << this->edition \
      << "\n\n";
}



// implementation of the class Film
Film::Film(
  string name, 
  string year,
  bool borrowed,
  string borrowedBy, 
  string director, 
  string language
) : Entry(name, year, borrowed, borrowedBy) {

  this->director = director;
  this->language = language;
};

// overriding the print function
void Film::printDetails() {
  cout << "Name: " << this->name \
      << "\nYear: " << this->year \
      << "\nBorrowed: " << (this->borrowed ? "Yes" : "No") \
      << (this->borrowed ? "\nBorrowed by: " : "") << this->borrowedBy \
      << "\nDirector: " << this->director \
      << "\nLanguage: " << this->language \
      << "\n\n";
}