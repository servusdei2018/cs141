// LAB4.cpp
// Nate Bracy
// 22 September 2023
//
// Determines toll based on Vehicle Class computed by Weight.

#include <iostream>

using namespace std;

int main() {
  // Get weight
  int weight;
  cout << "How much does your vehicle weigh? ";
  cin >> weight;

  // Determine class
  int vclass;
  if (weight <= 7000) {
    vclass = 1;
  } else if (weight >= 7001 && weight <= 15000) {
    vclass = 2;
  } else if (weight >= 15001 && weight <= 19000) {
    vclass = 3;
  } else if (weight >= 19001 && weight <= 30000) {
    vclass = 4;
  } else if (weight > 30000) {
    vclass = 5;
  }

  // Determine toll
  int toll;
  switch (vclass) {
    case 1:
      toll = 4;
      break;
    case 2:
      toll = 6;
      break;
    case 3:
      toll = 10;
      break;
    case 4:
      toll = 20;
      break;
    case 5:
      toll = 40;
      break;
  }

  cout << "Your vehicle is Class " << vclass << " and your toll will be $"
       << toll << "\n";
}
