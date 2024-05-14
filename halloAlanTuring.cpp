#include <iostream>
#include <string>

using namespace std;

void namenMitSternchen(string name) {
  // Bestimme die Länge des Namens ohne Leerzeichen
  string nameOhneLeerzeichen = name.replace(" ", "");
  int laengeNameOhneLeerzeichen = nameOhneLeerzeichen.length();

  // Berechne die Anzahl der benötigten Sternchen
  int anzahlSternchen = (laengeNameOhneLeerzeichen + 17) / 2;

  // Formatiere die Ausgabe
  string ausgabe = string(anzahlSternchen, '*') + " ** * Hallo " + name + "! * ** " + string(anzahlSternchen, '*');

  // Gebe die Ausgabe aus
  cout << ausgabe << '\n';
}

int main() {
  // Fordere den Namen vom Benutzer ein
  string name;
  cout << "Bitte geben Sie Ihren Namen ein: ";
  getline(cin, name);

  // Rufe die Funktion auf, um den Namen mit Sternchenumrandung auszugeben
  namenMitSternchen(name);

  return 0;
}