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
#include "qrdecomp.h"

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
  vector<Vector<double> > A;
  vector<Vector<double> > Q;
  vector<Vector<double> > R;
  Vector<double> * tempVector;
  Norm n;
  QRDecomp qrd;

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
      tempVector = new Vector<double>(dimensionSize);

      // Load vector into vectors
      inputFile >> *tempVector;
      A.push_back(*tempVector);

      // Clean up
      delete tempVector;

      // Q
      tempVector = new Vector<double>(dimensionSize);
      Q.push_back(*tempVector);
      delete tempVector;

      // R
      tempVector = new Vector<double>(dimensionSize);
      R.push_back(*tempVector);
      delete tempVector;
    }

    cout << "===" << endl;
    cout << A[0] + A[1];
    cout << "===" << endl;
    cout << A[0] - A[1];
    cout << "===" << endl;
    cout << A[0] * A[1] << endl;
    cout << "===" << endl;
    cout << A[0];
    cout << "===" << endl;
    cout << A[0][0] << endl;
    cout << "===" << endl;
    /*
    qrd(A, Q, R); CURRENTLY SEGFAULTS
    for(int i = 0; i < dimensionSize; i++)
    {
      for(int j = 0; j < dimensionSize; j++)
      {
        cout << Q[j][i] << "\t";
      }
      cout << endl;
    }
    */
    cout << "===" << endl;
    /*
    for(int i = 0; i < dimensionSize; i++)
    {
      for(int j = 0; j < dimensionSize; j++)
      {
        cout << R[j][i] << "\t";
      }
      cout << endl;
    }
     */
    cout << "===" << endl;
    /*
    for(int i = 0; i < dimensionSize; i++)
    {
      cout << Q[i] * Q[i] << endl;
    }
     */

  }
  else // If file isn't open
  {
    cout << "File failed to open: " << argv[1] << endl;
    return 1;
  }

  return 0;
}