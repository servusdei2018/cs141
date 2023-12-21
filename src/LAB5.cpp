// LAB5.cpp
// Nate Bracy
// 29 September 2023
//
// For 0-20, calculate the square, the cube, and the square root of the number.

#include <cmath>
#include <iostream>

using namespace std;

int square(int n) { return n * n; }
int cube(int n) { return square(n) * n; }

int main() {
  for (int i = 0; i <= 20; i++) {
    cout << "\t" << i << "\t" << square(i) << "\t" << cube(i) << "\t" << sqrt(i)
         << "\n";
  }
}
