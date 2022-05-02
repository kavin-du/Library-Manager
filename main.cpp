#include "headers.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  Entry entry("my entry", "2015", true, "someone");
  
  entry.printDetails();

  entry.entryReturned();

  entry.printDetails();

  return 0;
}
