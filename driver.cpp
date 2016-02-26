//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Connor McBride
/// @brief Main class file for Assignment 3 CS5201
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include "vector.h"
#include "norm.h"

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
  string dimensionSizeString;
  int dimensionSize;
  vector<Vector<int> > vectors;
  Vector<int> * tempVector;
  Norm n;

  // Start going through file
  if (inputFile.is_open())
  {
    // Take in the number of vectors & convert
    inputFile >> dimensionSizeString;
    dimensionSize = atoi(dimensionSizeString.c_str());

    // Load all vectors
    for(int i = 0; i < dimensionSize; i++)
    {
      // Allocate space
      tempVector = new Vector<int>(dimensionSize);

      // Load vector into vectors
      inputFile >> *tempVector;
      vectors.push_back(*tempVector);

      // Clean up
      delete tempVector;
    }

    // For each vector
    for(int i = 0; i < vectors.size(); i++)
    {
      cout << "i: " << i << endl;
      cout << vectors[i] << endl;
    }
    cout << "Addition: " << endl;
    cout << vectors[0] + vectors[1] << endl;
    cout << "Subtraction: " << endl;
    cout << vectors[0] - vectors[1] << endl;
    cout << "Multiplication: " << endl;
    cout << 4*vectors[0] << endl;
    cout << "Bracket: " << endl;
    cout << vectors[0][0] << endl;
    cout << "Dot Product: " << endl;
    cout << vectors[0] * vectors[1] << endl;
    cout << "Norm 1:" << endl;
    cout << n(vectors[0], 1) << endl;
    cout << "Norm 2:" << endl;
    cout << n(vectors[0], 2) << endl;
  }
  else // If file isn't open
  {
    cout << "File failed to open: " << argv[1] << endl;
    return 1;
  }

  return 0;
}