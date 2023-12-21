// LAB12.cpp
// Nate Bracy
// 2 December 2023
//
// Toy ATM program. Lets the user withdraw, deposit money and check balance.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Balance {
 private:
  int balance;

 public:
  void withdraw() {
    int amount;
    cout << "How much? ";
    cin >> amount;
    if (amount > balance)
      cout << "Insufficient funds\n";
    else {
      balance -= amount;
      cout << "Here is your money\n";
      cout << "New balance " << balance << endl;
    }
  }
  void deposit() {
    int amount;
    cout << "How much? ";
    cin >> amount;
    balance += amount;
    cout << "New balance " << balance << endl;
  }
  void read(ifstream &in) { in >> balance; }
  void write(ostream &out) { out << balance << endl; }
};

int main() {
  // Open input file
  ifstream in("balance.txt");
  char action;
  bool more = true;
  Balance bal;

  // Read balance
  bal.read(in);
  in.close();

  // Interactive loop
  cout << "Welcome to the ATM. Actions are (W)ithdraw (D)eposit (B)alance "
          "(Q)uit\n";
  do {
    cin >> action;
    switch (action) {
      // Check balance
      case 'b':
      case 'B':
        cout << "Balance ";
        bal.write(cout);
        break;
      // Withdraw money
      case 'W':
      case 'w':
        bal.withdraw();
        break;
      // Deposit money
      case 'd':
      case 'D':
        bal.deposit();
        break;
      // Quit
      case 'q':
      case 'Q':
        more = false;
        break;
      default:
        cout << action << " is not a valid action\n";
    }
  } while (more);

  // Persist data
  ofstream out("balance.txt");
  bal.write(out);
  out.close();
}
