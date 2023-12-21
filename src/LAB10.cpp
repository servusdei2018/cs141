// LAB10.cpp
// Nate Bracy
// 12 Nov 2023
//
// Play with a counter.

#include <iostream>

using namespace std;

class Counter {
 private:
  int counter;

 public:
  Counter(int count = 0) { counter = count; }
  void increment() { counter++; }
  void decrement() { counter--; }
  void print() { cout << counter; }
};

int main() {
  Counter c1;
  Counter c2(10);

  cout << "C1 starts at ";
  c1.print();
  cout << endl;

  c1.increment();
  c1.increment();

  cout << "C1 now at ";
  c1.print();
  cout << endl;

  c1 = c2;

  c1.decrement();

  cout << "C1 now at ";
  c1.print();
  cout << endl;

  return 0;
}
