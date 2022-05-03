 #include "headers.h"

#include <iostream>
using namespace std;

/**
 * 
 *  compile & run - 
 * 
 *  g++ *.cpp *.h -Wall -o output && ./output
 * 
 */

string getCategory() {
  string category;
  cout << "\nm. Music Album\n" \
          "b. Book\n" \
          "f. Film\n" \
          "Enter the category type: ";
  cin >> category;

  return category;
}

string getName() {
  string name;

  cout << "Name: ";
  cin.ignore(); // ignoring previous newline character
  getline(cin, name);

  return name;
}

int main(int argc, char const *argv[]) {

  MusicAlbum music("my music", "2015", false, "", "shawn", "new label");
  Book book("my book", "2016", false, "", "my author", "new publish", "3rd edition");
  Film film("my film", "2017", false, "", "steven", "mandarin");

  Catalogue catalogue; // not in the loop

  catalogue.addMusicAlbum(music);
  catalogue.addBook(book);
  catalogue.addFilm(film);


  cout << "== Welcome to Library Management System ==\n";

  while(1) {
    cout << "1. Add a new item to the library \n"
            "2. Delete an item from the library \n"
            "3. Issue an item \n"
            "4. Return item \n"
            "5. Print the catalog\n"
            "\nPress a number to continue:\n";

    string number;

    cin >> number;

    if(number == "1") {
      string category = getCategory();
      string name = getName();

      string year;
      cout << "Year: ";
      getline(cin, year);

      if(category == MUSIC_CAT) {
        string artist, recordLabel;

        cout << "Artist: ";
        getline(cin, artist);

        cout << "Record Label: ";
        getline(cin, recordLabel);

        MusicAlbum album(name, year, false, "", artist, recordLabel);

        catalogue.addMusicAlbum(album);

      } else if(category == BOOK_CAT) {
        string author, publisher, edition;

        cout << "author: ";
        getline(cin, author);

        cout << "Publisher: ";
        getline(cin, publisher);

        cout << "Edition: ";
        getline(cin, edition);

        Book book(name, year, false, "", author, publisher, edition);

        catalogue.addBook(book);

      } else if(category == FILM_CAT) {
        string director, language;

        cout << "Director: ";
        getline(cin, director);

        cout << "Language: ";
        getline(cin, language);

        Film film(name, year, false, "", director, language);

        catalogue.addFilm(film);

      }

      cout << "[INFO] Item successfully added.\n\n";

    } else if(number == "2") {
      string category = getCategory();
      string name = getName();      

      catalogue.deleteItem(category, name);

    } else if(number == "3") {
      string category = getCategory();
      string name = getName(); 

      catalogue.issueItem(category, name);
      
    } else if(number == "4") {

      string category = getCategory();
      string name = getName(); 

      catalogue.returnItem(category, name);
      
    } else if(number == "5") {
      catalogue.showCatalogue();
    } else {
      cout << "[ERROR] Invalid number.\n";
    }
  }

  return 0;
}

