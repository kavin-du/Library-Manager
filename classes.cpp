#include "headers.h"

#include <iostream>
#include <string>
#include <sstream>

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
    for(size_t i=0; i < this->films.size(); i++) {
      if(this->films[i].name == name) {
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

  cout << "[INFO] "<< name <<" removed from the catalogue.\n\n";
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

void Catalogue::saveToFile() {

  if(this->musicAlbums.size() == 0 && this->books.size() == 0 && this->films.size() == 0) {
    cout << "[INFO] Catalogue is empty. Nothing to save.\n\n";
    return;
  }

  string data = "";
  if(this->musicAlbums.size() != 0) {
    for(MusicAlbum item : this->musicAlbums) {
      data += "m"; // prefix
      data += (","+item.name+","+item.year+","+(item.borrowed ? "1": "0")+","+item.borrowedBy+","+item.artist+","+item.recordLabel);
      data += "\n";
    }
  } 
  if(this->books.size() != 0) {
    for(Book item : this->books) {
      data += "b"; // prefix
      data += (","+item.name+","+item.year+","+(item.borrowed ? "1": "0")+","+item.borrowedBy+","+item.author+","+item.publisher+","+item.edition);
      data += "\n";
    }
  } 
  if(this->films.size() != 0) {
    for(Film item : this->films) {
      data += "f"; // prefix
      data += (","+item.name+","+item.year+","+(item.borrowed ? "1": "0")+","+item.borrowedBy+","+item.director+","+item.language);
      data += "\n";
    }
  }

  // open the file in write-only mode, 
  // trunc - always replace the content rather than append to the end of file
  ofstream write_file(FILE_NAME, ios::out | fstream::trunc);

  if(write_file.is_open()) {
    write_file << data;  // write the data
  } else {
    cout << "[WARN] Cannot open the file.\n\n";
    return;
  }

  write_file.close();

  cout << "[INFO] Saved to file.\n\n";

}

void Catalogue::loadFromFile() {

  // open the file in read-only mode, 
  ifstream read_file(FILE_NAME, ios::in);

  string line, temp;

  if(read_file.is_open()) {
    string values[8];
    int i;
    while(getline(read_file, line)) { // read each line
      i = 0;
      stringstream data_stream(line);
      while(getline(data_stream, temp, ',')) { // tokenize each line
        values[i++] = temp;
      }
      
      if(values[0] == MUSIC_CAT) {
        MusicAlbum album(values[1], values[2], values[3] == "1" ? true : false, values[4], values[5], values[6]);
        this->addMusicAlbum(album);
      } else if(values[0] == BOOK_CAT) {
        Book book(values[1], values[2], values[3] == "1" ? true : false, values[4], values[5], values[6], values[7]);
        this->addBook(book);
      } else if(values[0] == FILM_CAT) {
        Film film(values[1], values[2], values[3] == "1" ? true : false, values[4], values[5], values[6]);
        this->addFilm(film);
      }
    }
  } else {
    cout << "[WARN] Cannot open the file.\n\n";
    return;
  }

  read_file.close();

  cout << "[INFO] Data loaded successfully.\n\n";

}