// LAB7.CPP
// Nate Bracy
// 19 October 2023
//
// Write advice to screen, take advice and show it to the next user.
// Persists advice between invocations.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream in;
  string data;
  bool more = true;
  in.open("advice.txt");
  cout << ">>>Previous advice:\n";
  while (more) {
    getline(in, data);
    if (in.eof())
      more = false;
    else
      cout << data << endl;
  }
  in.close();

  ofstream out;
  cout << ">>>Your advice to the next user. Hit ENTER twice to exit:\n";
  more = true;
  bool lastendl = false;
  char c;
  out.open("advice.txt");
  while (more) {
    c = cin.get();
    if (c == '\n') {
      if (lastendl)
        more = false;
      else
        lastendl = true;
      out << c;
    } else {
      lastendl = false;
      out << c;
    }
  }
  out.close();
}
