#include <string>
#include <vector>

#ifndef ENTRY_H
#define ENTRY_H

class Entry {

  public: 
    std::string name;
    std::string year;
    bool borrowed;
    std::string borrowedBy;

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


#ifndef BOOK_H
#define BOOK_H

class Book : public Entry {
  private:
    std::string author;
    std::string publisher;
    std::string edition;

  public: 

    Book();

    Book(
      std::string name, 
      std::string year, 
      bool borrowed, 
      std::string borrowedBy, 
      std::string author, 
      std::string publisher,
      std::string edition
    );

    void printDetails();
};

#endif



#ifndef FILM_H
#define FILM_H

class Film : public Entry {
  private:
    std::string director;
    std::string language;

  public: 
    Film();

    Film(
      std::string name, 
      std::string year, 
      bool borrowed, 
      std::string borrowedBy, 
      std::string director, 
      std::string language
    );

    void printDetails();
};

#endif

#ifndef CATALOGUE_H
#define CATALOGUE_H

#define MUSIC_CAT "m"
#define BOOK_CAT "b"
#define FILM_CAT "f"

class Catalogue {
  private:
    std::vector<MusicAlbum> musicAlbums;
    std::vector<Book> books;
    std::vector<Film> films;

  public: 
    void addMusicAlbum(MusicAlbum album); // category 'm'
    void addBook(Book book); // category 'b'
    void addFilm(Film film); // category 'f'

    void showMusicAlbums();
    void showBooks();
    void showFilms();
    void showCatalogue();

    int getIndexByName(std::string category, std::string name);
    void deleteItem(std::string category, std::string name);

    void chargeFees();
    std::string getMemberNumber();
    void issueItem(std::string category, std::string name);

    void returnItem(std::string category, std::string name);

    void saveToFile();
    
};

#endif