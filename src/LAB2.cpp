// LAB2.cpp
// Nate Bracy
// 8 September 2023
//
// Lets a user check their balance, deposit money, withdraw money, or exit with
// no operation.
//
// Account balance is set to 1000 initially, and is not persisted across
// invocations.

#include <iostream>
#include <string>

using namespace std;

// forward declaration of helper function
void showBalance(int);

int main() {
  // Print options
  cout << "Select an option:\n";
  cout << "--[C]heck balance\n";
  cout << "--[D]eposit\n";
  cout << "--[W]ithdraw\n";
  cout << "--[E]xit\n";

  // Read option
  string option;
  cin >> option;

  // Declare balance
  int balance = 1000;

  // Handle option selected
  // This would be a good candidate for a switch statement
  if (option == "C" || option == "c") {
    // Display their balance
    showBalance(balance);
  } else if (option == "D" || option == "d") {
    // Prompt the user for the deposit amount
    int amount;
    cout << "How much money would you like to deposit?\n";
    cin >> amount;
    // Ensure deposit is positive
    if (amount < 1) {
      cout << "You must enter a positive amount.\n";
      return 0;
    }
    // Deposit the amount to their balance
    balance += amount;
    // Display their new balance
    showBalance(balance);
  } else if (option == "W" || option == "w") {
    // Prompt the user for their withdrawal amount
    int amount;
    cout << "How much money would you like to withdraw?\n";
    cin >> amount;
    // Ensure withdrawal is positive
    if (amount < 1) {
      cout << "You must enter a positive amount.\n";
      return 0;
    }
    // Check for sufficient funds
    if (amount > balance) {
      cout << "You lack sufficient funds to complete this transaction.\n";
      return 0;
    }
    // Withdrraw the amount from their balance
    balance -= amount;
    // Display their new balance
    showBalance(balance);
  } else if (option == "E" || option == "e") {
    return 0;
  } else {
    cout << "Invalid option.\n";
  }
}

// showBalance displays a balance to the user
void showBalance(int balance) {
  cout << "Your current balance is: " << balance << "\n";
}
