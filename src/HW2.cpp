// HW2.cpp
// Nate Bracy
// 25 September 2023
//
// Asks for number of students.
//
// For each student:
//   Asks user for first and last name, and scores for homework 1 & 2.
//   Then, prints them out on one line along with a letter grade.
//
// Then, calculates an overall average for all the students.

#include <iostream>
#include <string>

using namespace std;

// forward declaration of helper function
double getStudent(int studentNumber);

int main() {
  // Get number of students
  int students;
  cout << "How many students? ";
  cin >> students;

  // Collect students
  double runningTotal;
  for (int i = 1; i <= students; i++) {
    runningTotal += getStudent(i);
  }
  cout << "Overall average: " << runningTotal / students << "\n";
}

// getStudent prompts for input regarding student data
double getStudent(int studentNumber) {
  // Get first name
  string firstName, lastName;
  cout << "For student " << studentNumber << " enter first and last name: ";
  cin >> firstName >> lastName;

  // Get homework scores
  int hw1Score, hw2Score;
  cout << "Enter two homework scores: ";
  cin >> hw1Score >> hw2Score;

  // Calculate total
  double total = hw1Score + hw2Score;

  // Calculate average
  double average = total / 2;

  // Determine letter grade
  char letterGrade;
  if (average >= 90)
    letterGrade = 'A';
  else if (average >= 80)
    letterGrade = 'B';
  else if (average >= 70)
    letterGrade = 'C';
  else if (average >= 60)
    letterGrade = 'D';
  else
    letterGrade = 'F';

  // Display results on a new line
  cout << firstName << " " << lastName << " " << hw1Score << " " << hw2Score
       << " " << total << " " << average << " " << letterGrade << endl;
  return average;
}
