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

#ifndef MUSICALBUM_H
#define MUSICALBUM_H

class MusicAlbum : public Entry {
  private:
    std::string artist;
    std::string recordLabel;

  public: 
    MusicAlbum();

    MusicAlbum(
      std::string name, 
      std::string year, 
      bool borrowed, 
      std::string borrowedBy, 
      std::string artist, 
      std::string recordLabel
    );

    void printDetails();
};

#endif


// #ifndef BOOK_H
// #define BOOK_H

// class Book : public Entry {
//   private:
//     std::string author;
//     std::string publisher;
//     std::string edition;

//   public: 

//     Book();

//     Book(
//       std::string name, 
//       std::string year, 
//       bool borrowed, 
//       std::string borrowedBy, 
//       std::string author, 
//       std::string publisher,
//       std::string edition
//     );
// };

// #endif



// #ifndef FILM_H
// #define FILM_H

// class Film : public Entry {
//   private:
//     std::string director;
//     std::string language;

//   public: 
//     Film();

//     Film(
//       std::string name, 
//       std::string year, 
//       bool borrowed, 
//       std::string borrowedBy, 
//       std::string director, 
//       std::string language
//     );
// };

// #endif