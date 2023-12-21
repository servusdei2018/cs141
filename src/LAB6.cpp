// LAB6.cpp
// Nate Bracy
// 15 October 2023
//
// Convert pounds and ounces to kilograms and grams.

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void pounds_to_kg(float lb, float oz, int* kg, float* g);

int main() {
  float lb, oz;
  int kg;
  float g;
  string choice;
  while (true) {
    cout << "Pounds and Ounces?" << endl;
    cin >> lb >> oz;
    cout << "Pounds:\t" << lb << "\t"
         << "ounces:\t" << oz << endl;
    pounds_to_kg(lb, oz, &kg, &g);
    cout << "KG:\t" << kg << "\t"
         << "G:\t" << g << endl;
    cout << "Keep going? (Y)es or (N)o" << endl;
    cin >> choice;
    if (choice == "N" || choice == "n") break;
  }
}

// convert pounds and ounces to kilograms and grams
void pounds_to_kg(float lb, float oz, int* kg, float* g) {
  *kg = round((lb * 16 * 28.3495) / 1000);
  *g = oz * 28.3495;
}
