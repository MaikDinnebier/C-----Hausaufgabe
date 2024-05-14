#include <iostream>

using namespace std;

int main() {
  int i = 10;

  // Präfix-Inkrement
  cout << "Präfix-Inkrement: " << ++i << endl; // Ausgabe: 11
  cout << "i nach Präfix-Inkrement: " << i << endl; // Ausgabe: 11

  // Postfix-Inkrement
  i = 10;
  cout << "Postfix-Inkrement: " << i++ << endl; // Ausgabe: 10
  cout << "i nach Postfix-Inkrement: " << i << endl; // Ausgabe: 11

  return 0;
}