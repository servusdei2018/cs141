// HW4.cpp
// Nate Bracy
// 2 November 2023
//
// Given a file containing student information and grades, compute
// the average and letter grade for each student and write them to
// cout, pretty-printing them in orderly columns.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Record {
  string firstname, lastname;
  double hw[2], average;
  string lettergrade;
};

void calc_grade(Record &record);
void print_record(Record record);

int main() {
  // Get input filename
  char filename[255];
  cout << "Filename: ";
  cin >> filename;

  // Open inputfile
  ifstream in;
  in.open(filename);

  // Read amount of records
  int numrecords;
  in >> numrecords;

  // Read records
  vector<Record> records;
  Record tmpr;
  for (int count = 0; count < numrecords; count++) {
    in.get();
    getline(in, tmpr.lastname);
    in >> tmpr.firstname >> tmpr.hw[0] >> tmpr.hw[1];
    records.push_back(tmpr);
  }
  in.close();

  // Compute grades
  for (unsigned int i = 0; i < records.size(); i++) {
    calc_grade(records[i]);
  }

  // Display column titles
  cout.width(20);
  cout.setf(ios::left);
  cout << "First";
  cout.unsetf(ios::left);
  cout.width(20);
  cout.setf(ios::left);
  cout << "Last";
  cout.unsetf(ios::left);
  cout.width(20);
  cout << "Average";
  cout.width(20);
  cout.setf(ios::right);
  cout << "Letter" << endl;
  cout.unsetf(ios::right);
  cout << string(80, '#') << endl;

  // Display records
  for (unsigned int i = 0; i < records.size(); i++) {
    print_record(records[i]);
  }
}

void calc_grade(Record &record) {
  record.average = (record.hw[0] + record.hw[1]) / 2;
  if (record.average >= 90)
    record.lettergrade = 'A';
  else if (record.average >= 80)
    record.lettergrade = 'B';
  else if (record.average >= 70)
    record.lettergrade = 'C';
  else if (record.average >= 60)
    record.lettergrade = 'D';
  else
    record.lettergrade = 'F';
}

void print_record(Record record) {
  cout.precision(2);
  cout.width(20);
  cout << fixed;
  cout.setf(ios::left);
  cout << record.firstname;
  cout.unsetf(ios::left);
  cout.width(20);
  cout.setf(ios::left);
  cout << record.lastname;
  cout.unsetf(ios::left);
  cout.width(20);
  cout << record.average;
  cout.width(20);
  cout.setf(ios::right);
  cout << record.lettergrade << endl;
  cout.unsetf(ios::right);
}
