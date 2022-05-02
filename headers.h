#include <string>

#ifndef ENTRY_H
#define ENTRY_H

class Entry {
  protected:
    std::string name;
    std::string year;
    bool borrowed;
    std::string borrowedBy;

  public: 
    Entry();

    Entry(
      std::string name, 
      std::string year,
      bool borrowed,
      std::string borrowedBy
    );

    void entryBorrowed(std::string name);
    void entryReturned();
    virtual void printDetails();
};

#endif

// #ifndef MUSICALBUM_H
// #define MUSICALBUM_H

// class MusicAlbum : public Entry {
//   private:
//     string artist;
//     string recordLabel;

//   public: 
//     MusicAlbum();

//     MusicAlbum(
//       string name, 
//       string year, 
//       bool borrowed, 
//       string borrowedBy, 
//       string artist, 
//       string recordLabel
//     );
// };

// #endif


// #ifndef BOOK_H
// #define BOOK_H

// class Book : public Entry {
//   private:
//     string author;
//     string publisher;
//     string edition;

//   public: 

//     Book();

//     Book(
//       string name, 
//       string year, 
//       bool borrowed, 
//       string borrowedBy, 
//       string author, 
//       string publisher,
//       string edition
//     );
// };

// #endif



// #ifndef FILM_H
// #define FILM_H

// class Film : public Entry {
//   private:
//     string director;
//     string language;

//   public: 
//     Film();

//     Film(
//       string name, 
//       string year, 
//       bool borrowed, 
//       string borrowedBy, 
//       string director, 
//       string language
//     );
// };

// #endif