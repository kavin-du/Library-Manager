#include "headers.h"

#include <iostream>
using namespace std;

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

  Catalogue catalogue;

  catalogue.addMusicAlbum(m1);
  catalogue.addMusicAlbum(m2);

  catalogue.showCatalogue();

  catalogue.deleteItem('m', "sdfsdf sdf");
  // catalogue.deleteItem('m', "my entry");

  catalogue.issueItem('m', "my entry");
  catalogue.showCatalogue();

  catalogue.returnItem('m', "my entry");
  catalogue.showCatalogue();
  
  return 0;
}

