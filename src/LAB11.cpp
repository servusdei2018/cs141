// LAB11.cpp
// Nate Bracy
// 24 November 2023
//
// Given a file full of numbers (such that 0<n<100), determine their
// max, min and average and write them to an output file.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Open file for reading
  ifstream ifile("/home/mingli/public/f23_lab11_input.txt");

  // Read number of numbers
  int recordcount;
  ifile >> recordcount;

  // Collect numbers
  int records[100];
  int tmp;
  double total;
  for (int i = 0; i < recordcount; i++) {
    ifile >> tmp;
    records[i] = tmp;
    total += tmp;
  }
  ifile.close();

  // Compute max, min, and average
  int max, min;
  double avg = total / recordcount;
  max = records[0];
  min = records[0];
  for (int i = 0; i < recordcount; i++) {
    if (records[i] > max) max = records[i];
    if (records[i] < min) min = records[i];
  }

  // Write metrics to output file
  ofstream ofile;
  ofile.open("output.txt");
  cout << ">>>MAX = " << max << endl;
  ofile << ">>>MAX = " << max << endl;
  cout << ">>>MIN = " << min << endl;
  ofile << ">>>MIN = " << min << endl;
  cout << ">>>AVG = " << avg << endl;
  ofile << ">>>AVG = " << avg << endl;
  ofile.close();
}
