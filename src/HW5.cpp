// HW5.cpp
// Nate Bracy
// 28 November 2023
//
// Given a file containing student information and grades, compute
// the average and letter grade for each student. Stores them in
// memory, and provides a CLI interface to lookup records by name or
// by their number.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Record {
 private:
  string firstname, lastname;
  double hw[2], average;
  string lettergrade;

 public:
  void read(istream &infile) {
    infile.get();
    getline(infile, lastname);
    infile >> firstname >> hw[0] >> hw[1];
  }
  void calc() {
    average = (hw[0] + hw[1]) / 2;
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
  void write() {
    cout << string(80, '-') << endl;
    cout << "Name (last, first): " << lastname << ", " << firstname << endl;
    cout << "Grade average     : " << average << endl;
    cout << "Letter grade      : " << lettergrade << endl;
    cout << string(80, '-') << endl;
  }
  bool match(string target) { return target == lastname; }
};

int main() {
  // Get filename
  char filename[255];
  cout << "Filename: ";
  cin >> filename;

  // Open infile
  ifstream in;
  in.open(filename);

  // Get number of records
  int numrecords;
  in >> numrecords;

  // Read records
  vector<Record> records;
  for (int count = 0; count < numrecords; count++) {
    Record tmpr;
    tmpr.read(in);
    tmpr.calc();
    records.push_back(tmpr);
  }
  in.close();

  cout << numrecords << " records processed." << endl;

  // Read and evaluate loop
  string option, query;
  int number;
  while (true) {
    cout << "Lookup record by 1) Last name  2) Number (Q to quit) [1/2/Q]: ";
    cin >> option;
    // Quit
    if (option == "Q" || option == "q") break;
    // Invalid option
    if (option != "1" && option != "2") {
      cout << "Please enter 1 or 2." << endl;
      continue;
    }
    // Lookup record by last name
    if (option == "1") {
      cout << "Enter last name: ";
      getline(cin >> ws, query);
      bool found = false;
      for (int i = 0; i < numrecords; i++) {
        if (records[i].match(query)) {
          found = true;
          records[i].write();
          break;
        }
      }
      if (!found) {
        cout << "No record found with that last name." << endl;
      }
      // Lookup record by record number
    } else {
      cout << "Enter record number (1-" << numrecords << "): ";
      cin >> number;
      if (number > numrecords || number < 1) {
        cout << "Invalid number." << endl;
        continue;
      }
      records[number - 1].write();
    }
  }
}
