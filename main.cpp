#include "headers.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  // Entry entry("my entry", "2015", true, "someone");
  // entry.printDetails();
  // entry.entryReturned();
  // entry.printDetails();

  MusicAlbum musicAlbum("my entry", "2015", true, "someone", "shawn", "new label");
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

  catalogue.addMusicAlbum(musicAlbum);

  return 0;
}

