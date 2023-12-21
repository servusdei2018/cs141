// HW1.cpp
// Nate Bracy
// 7 September 2023
//
// Asks user for first and last name, and scores for homework 1 & 2.
// Then, prints them out on one line.

#include <iostream>
#include <string>

using namespace std;

int main() {
  // Get first name
  string firstName;
  cout << "First name: ";
  cin >> firstName;

  // Get last name
  string lastName;
  cout << "Last name: ";
  cin >> lastName;

  // Get homework 1 score
  int hw1Score;
  cout << "Homework 1 Score: ";
  cin >> hw1Score;

  // Get homework 2 score
  int hw2Score;
  cout << "Homework 2 Score: ";
  cin >> hw2Score;

  // Calculate total
  const double total = hw1Score + hw2Score;

  // Calculate average
  const double average = total / 2;

  // Display results on a new line
  cout << "----------------------" << endl;
  cout << firstName << " " << lastName << " " << hw1Score << " " << hw2Score
       << " " << total << " " << average << endl;
}
