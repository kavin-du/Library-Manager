#include "headers.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  // Entry entry("my entry", "2015", true, "someone");
  // entry.printDetails();
  // entry.entryReturned();
  // entry.printDetails();

  MusicAlbum musicAlbum("my entry", "2015", true, "someone", "shawn", "new label");
  musicAlbum.printDetails();
  musicAlbum.entryReturned();
  musicAlbum.printDetails();

  return 0;
}

