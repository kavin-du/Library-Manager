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


// implementation of class Catalogue
void Catalogue::addMusicAlbum(MusicAlbum album) {
  this->musicAlbums.push_back(album);
}

void Catalogue::addBook(Book book) {
  this->books.push_back(book);
}

void Catalogue::addFilm(Film film) {
  this->films.push_back(film);
}

void Catalogue::showMusicAlbums(){
  if(this->musicAlbums.size() == 0) {
    cout << "[INFO] No music albums. \n\n";
    return;
  }
  for(MusicAlbum album: this->musicAlbums){
    album.printDetails();
  }
}

void Catalogue::showBooks(){
  if(this->books.size() == 0) {
    cout << "[INFO] No books. \n\n";
    return;
  }
  for(Book book: this->books){
    book.printDetails();
  }
}

void Catalogue::showFilms(){
  if(this->films.size() == 0) {
    cout << "[INFO] No films. \n\n";
    return;
  }
  for(Film film: this->films){
    film.printDetails();
  }
}

// show everything in the catalogue
void Catalogue::showCatalogue(){
  cout << "==========================\n";
  this->showMusicAlbums();
  this->showBooks();
  this->showFilms();
  cout << "==========================\n";
}


// helper function to get the index
int Catalogue::getIndexByName(string category, string name) {
  if(category == MUSIC_CAT) {
    for(size_t i=0; i < this->musicAlbums.size(); i++) {
      if(this->musicAlbums[i].name == name) {
        return static_cast<int>(i);
      }
    }
  } else if(category == BOOK_CAT) {
    for(size_t i=0; i < this->books.size(); i++) {
      if(this->books[i].name == name) {
        return static_cast<int>(i);
      }
    }
  } else if(category == FILM_CAT) {
    for(size_t i=0; i < this->books.size(); i++) {
      if(this->books[i].name == name) {
        return static_cast<int>(i);
      }
    }
  } else {
    cout << "[ERROR] Invalid category type.\n\n";
  }

  return -99; // return negative index if not found
}

void Catalogue::deleteItem(string category, string name) {
  int index = getIndexByName(category, name);
  if(index < 0) {
    cout << "[ERROR] Item not found\n\n";
    return;
  }

  if(category == MUSIC_CAT) {
    this->musicAlbums.erase(this->musicAlbums.begin() + index);
  } else if(category == BOOK_CAT) {
    this->books.erase(this->books.begin() + index);
  } else if(category == FILM_CAT) {
    this->films.erase(this->films.begin() + index);
  } 

  cout << name << "[INFO] Removed from the catalogue.\n\n";
}

// member function for charging fees
void Catalogue::chargeFees() {
  cout << "[INFO] You have been charged for borrowing this item.\n";
}

// ge the library member number from the user
string Catalogue::getMemberNumber() {
  string number;

  cout << "Enter your library member number:\n";
  cin >> number;
  return number;
}

void Catalogue::issueItem(string category, string name) {
  int index = getIndexByName(category, name);
  if(index < 0) {
    cout << "[ERROR] Item not found\n\n";
    return;
  }

  // if the category is films, we need to charge the user
  if(category == FILM_CAT) {
    this->chargeFees();
  }

  string memberNumber = this->getMemberNumber();

  if(category == MUSIC_CAT) {
    this->musicAlbums[index].entryBorrowed(memberNumber);
  } else if(category == BOOK_CAT) {
    this->books[index].entryBorrowed(memberNumber);
  } else if(category == FILM_CAT) {
    this->films[index].entryBorrowed(memberNumber);
  }

  cout << "[INFO] Item successfully issued.\n\n";

}

void Catalogue::returnItem(string category, string name) {
  int index = getIndexByName(category, name);
  if(index < 0) {
    cout << "[ERROR] Item not found\n\n";
    return;
  }

  if(category == MUSIC_CAT) {
    this->musicAlbums[index].entryReturned();
  } else if(category == BOOK_CAT) {
    this->books[index].entryReturned();
  } else if(category == FILM_CAT) {
    this->films[index].entryReturned();
  }

  cout << "[INFO] Item successfully returned.\n\n";

}