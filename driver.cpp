//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Connor McBride
/// @brief Main class file for Assignment 3 CS5201
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "vector.h"

using namespace std;

int main(int argc, char* argv[])
{
  // If no file from arg commands
  if (argc < 2)
  {
    cout << "No file given." << endl;
    return 1;
  }

  // Declare variables
  ifstream inputFile(argv[1]);
  string dimensionSize;
  Vector<double> v;

  // Start going through file
  if (inputFile.is_open())
  {
    inputFile >> dimensionSize;
    cout << v << endl;
    inputFile >> v;
    cout << v << endl;
    cout << dimensionSize << endl;
  }
  else // If file isn't open
  {
    cout << "File failed to open: " << argv[1] << endl;
    return 1;
  }

  cout << "Hello, World!" << endl;
  return 0;
}