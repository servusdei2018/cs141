// LAB3.cpp
// Nate Bracy
// 15 September 2023
//
// Iteratively ask for a number then tally their sum until a negative number is
// input.

#include <iostream>

using namespace std;

int main() {
  int input, tally;
  while (true) {
    cout << "Enter a number: ";
    cin >> input;
    if (input < 0) break;
    tally += input;
  }
  cout << "Sum = " << tally << endl;
}
