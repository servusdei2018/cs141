// LAB1.cpp
// Nate Bracy
// 31 August 2023
//
// Perform division and output the quotient and a remainder.

#include <iostream>

using namespace std;

int main() {
  // Collect input
  int numerator, denominator;
  cout << "Enter numerator:  ";
  cin >> numerator;
  cout << "Enter denominator: ";
  cin >> denominator;

  // Sanity check
  if (numerator < denominator) {
    cout << "Numerator has to > denominator.\n";
    return 0;
  }

  // Declare results
  int quotient, remainder;

  // Check for a fraction equal to one
  if (numerator == denominator) {
    cout << "-----------------\nQuotient = 1\nRemainder = 0\n";
    return 0;
  }

  // Subtract the denominator from the numerator until it is impossible to do so
  for (;;) {
    if (numerator == denominator) {
      quotient++;
      break;
    }
    if (numerator < denominator) {
      remainder = numerator;
      break;
    }
    numerator -= denominator;
    quotient++;
  }

  // Declare results
  cout << "---------------------\n";
  cout << "Quotient = " << quotient << "\n";
  cout << "Remainder = " << remainder << "\n";
}
