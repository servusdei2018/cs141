// HW3.cpp
// Nate Bracy
// 19 October 2023
//
// Given a file containing student information and grades, compute
// the average and letter grade for each student and write them to
// a report file. Additionally, calculate and output an overall
// average for all students.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void calc_grade(double hw1, double hw2, double &average, char &lettergrade);

int main() {
  // Get input filename
  char filename[255];
  cout << "Filename: ";
  cin >> filename;

  // Open file for reading, and another for the report
  ifstream in;
  in.open(filename);
  ofstream out;
  out.open("report.txt");

  // Read amount of records
  int records;
  in >> records;

  // Get records from file, compute grade and running total
  string lastname, firstname;
  double hw1, hw2, average, runningTotal;
  char lettergrade;
  for (int count = 0; count < records; count++) {
    in.get();
    getline(in, lastname);
    in >> firstname >> hw1 >> hw2;
    calc_grade(hw1, hw2, average, lettergrade);
    runningTotal += average;
    out << firstname << " " << lastname << " " << average << " " << lettergrade
        << endl;
  }

  // Write overall average (of all students) and close files
  double overallaverage = runningTotal / records;
  out << overallaverage << endl;
  in.close();
  out.close();
}

// Calculate the average and letter grade based on two homework scores
void calc_grade(double hw1, double hw2, double &average, char &lettergrade) {
  average = (hw1 + hw2) / 2;
  if (average >= 90)
    lettergrade = 'A';
  else if (average >= 80)
    lettergrade = 'B';
  else if (average >= 70)
    lettergrade = 'C';
  else if (average >= 60)
    lettergrade = 'D';
  else
    lettergrade = 'F';
}
