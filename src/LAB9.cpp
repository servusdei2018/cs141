// LAB9.cpp
// Nate Bracy
// 4 November 2023
//
// Collect, print information about three people.

#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  int age;
  string gender;
};

int main() {
  Person people[3];

  for (int i = 0; i < 3; i++) {
    cout << "Enter information for Person " << i + 1 << ":" << endl;
    cout << "Name: ";
    cin >> people[i].name;
    cout << "Age: ";
    cin >> people[i].age;
    cout << "Gender: ";
    cin >> people[i].gender;
  }

  cout << endl << "Here is the information you entered:" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "Person " << i + 1 << ":" << endl;
    cout << "Name: " << people[i].name << endl;
    cout << "Age: " << people[i].age << endl;
    cout << "Gender: " << people[i].gender << endl << endl;
  }
}
