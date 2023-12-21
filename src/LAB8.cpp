// LAB8.cpp
// Nate Bracy
// 27 October 2023
//
// Calculate the average and standard deviation for a series of numbers.

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Open file for reading
  ifstream ifile("numbers.txt");

  // Read numbers
  vector<double> numbers;
  double n;
  while (ifile >> n) {
    numbers.push_back(n);
  }
  ifile.close();

  // Determine total
  double total;
  for (int i = 0; i < numbers.size(); i++) {
    total += numbers[i];
  }

  // Determine average
  double average = total / numbers.size();

  // Determine the sum of squares
  double sumsquares;
  for (int i = 0; i < numbers.size(); i++) {
    double d = numbers[i] - average;
    sumsquares += d * d;
  }

  // Determine variance and standard deviation
  double variance = sumsquares / numbers.size();
  double stddev = sqrt(variance);

  // Display computed data
  cout << "Average is " << average << endl;
  cout << "Standard deviation is " << stddev << endl;
}
