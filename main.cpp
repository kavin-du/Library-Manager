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

int main(int argc, char const *argv[]) {

  // Entry entry("my entry", "2015", true, "someone");
  // entry.printDetails();
  // entry.entryReturned();
  // entry.printDetails();

  MusicAlbum m1("my entry", "2015", true, "someone", "shawn", "new label");
  MusicAlbum m2("my entry2", "2015", true, "someddone", "shaddwn", "label");
  // musicAlbum.printDetails();
  // musicAlbum.entryReturned();
  // musicAlbum.printDetails();

  // Book book("my entry", "2015", true, "micheal", "my author", "new publish", "new edition");
  // book.printDetails();
  // book.entryReturned();
  // book.printDetails();

  // Film film("my entry", "2015", true, "someone", "steven", "mandarin");
  // film.printDetails();
  // film.entryReturned();
  // film.printDetails();

  Catalogue catalogue; // not in the loop

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
      string category;
      cout << "\nm. Music Album\n" \
              "b. Book\n" \
              "f. Film\n" \
              "Enter the category type:\n";
      cin >> category;

      if(category == MUSIC_CAT) {
        string name, year;
        string artist, recordLabel;

        cout << "Name: \n";
        cin.ignore();
        getline(cin, name);

        cout << "Year: \n";
        cin >> year;

        cout << "Artist: \n";
        cin.ignore();
        getline(cin, artist);

        cout << "Record Label: \n";
        getline(cin, recordLabel);

        MusicAlbum album(name, year, false, "", artist, recordLabel);

        catalogue.addMusicAlbum(album);

        cout << "[INFO] Item successfully added.\n\n";
      }

    } else if(number == "2") {
      
    } else if(number == "3") {
      
    } else if(number == "4") {
      
    } else if(number == "5") {
      catalogue.showCatalogue();
    } else {
      cout << "[ERROR] Invalid number.\n";
    }
  }

  return 0;
}

