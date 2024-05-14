//1.Was ist falsch mit dem folgenden Code und wie würdest du ihn verbessern?
//Map<int,string>::iterator i = m.find(13);
//if (i != m.end())
//{
//  const_cast<int&>(i->first) = 9999999;
//}

//Antwort: Der Code versucht, den Wert des Schlüssels (den int) in der Map zu ändern, was nicht erlaubt ist. M
//aps in C++ sind assoziative Container, d.h. die Schlüssel sind fest und können nicht nachträglich geändert werden.
//Wenn Sie den Wert eines Schlüssels ändern möchten, sollten Sie stattdessen einen neuen Schlüssel-Wert-Paar mit dem gewünschten Wert hinzufügen und den alten Eintrag ggf. entfernen.
//if (i != m.end()) {
//    m[i->first] = 9999999; // Wert ändern
    // m.erase(i); // Alten Eintrag entfernen, falls gewünscht
//}
//Alternativ können Sie einen neuen Schlüssel erstellen und den gewünschten Wert damit zuordnen.
//int newKey = 9999999;
//m[newKey] = i->second; // Wert mit neuem Schlüssel zuordnen
//verbesserte Lösung: 
//Map<int, string>::iterator i = m.find(13);
//if (i != m.end()) {
//    m[i->first] = 9999999; // Wert ändern
    // m.erase(i); // Alten Eintrag entfernen, falls gewünscht
//} else {
    // Schlüssel nicht gefunden, ggf. Fehlermeldung ausgeben
//}

//Aufgabe 2 Vorlesung 06.05.2024
// #include <iostream>
// #include <fstream>

// int main() {
//     //Dateinamen definieren
//     std::string dateiname = "ausgabe.txt";

//     //Datei im Schreibmodus öffnen
//     std::ofstream datei(dateiname);

//     if (!datei.is_open()) {
//         std::cerr << "Fehler beim Öffnen der Datei: " << dateiname << std::endl;
//         return 1;
//     }

//     //Schreiben von Zeichen und Zahlen in die Datei mit dem Ausgebeoperator (<<)
//     datei << "Dies ist ein Zeichen: " << std::endl;
//     datei << "Dies ist eine Zahl: " << 10 << std::endl;
//     datei << "Dies ist gemischt: " << "Zeichen " << 42 << std::endl;

//     //Datei schließen
//     datei.close();

//     //Bestätigungsmeldung 
//     std::cout << "Datei '" << dateiname << "' erfolgreich erstellt." << std::endl;

//     //Öffnen der Datei mit dem standardmäßigen Texteditor (Betriebssystem abhängig)
//     //Plattformübergreifende Lösung schwierig, da Betriebssysteme eigene APIs nutzen
//     // Unter Windows:
//     #ifdef _WIN32
//     system(("start " + dateiname).c_str());
//     #endif

//     return 0;
// }
// //Rekursive Dateisuche mit Plattenplatzberechnung und Benutzeingabe

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <filesystem>
// #include <string>

// using namespace std;
// using namespace std::filesystem;

// //Funktion zum Berechnen des Plattenplatzverbrauchs einer Datei
// long long dateiGroesseBerechnen(const path& dateiPfad) {
//     if (!exists(dateiPfad)) {
//         return 0;
//     }

//     if (is_directory(dateiPfad)) {
//         return 0; //Verzeichnisse werden nicht gezählt
//     }
//     return file_size(dateiPfad);
// }

// //Funktion zum rekursiven Dursuchen eines Verzeichnisses und Berechnen des Plattenplatzverbrauchs
// long long verzeichnisDurchsuchen(cons path& verzeichnisPfad, const string& extension) {
//     long long gesamtGroesse = 0;

//     for (auto& entry : directory_iterator(verzeichnisPfad)) {
//         const path& dateiPfad = entry.path();

//         if (is_directory(dateiPfad)) {
//             gesamtGroesse += verzeichnisDurchsuchen(dateiPfad, extension);
//         }else if (!extension.empts() && dateiPfad.extension() == extension) {
//         } else if (extension.empty()){
//             gesamtGroesse += dateiGroesseBerechnen(dateiPfad);
//         } 
//     }
//     return gesamtGroesse;
// }

// int main() {
//     string verzeichnisEingabe;
//     string extensionEingabe;

//     //Schleife zur wiederholten Verzeichniseingabe bis ein gültiges Verzeichnis eingegeben wird
//   do {
//     cout << "Geben Sie bitte das Verzeichnis ein: ";
//     getline(cin, verzeichnisEingabe);
// } while (!exists(verzeichnisEingabe));

// //Optionale Eingabe der Extension
// cout << "Geben Sie bitte die Extension ein (ohne \"): ";
// getline(cin, extensionEingabe);

// //Berechnung des Plattenverbrauchs
// long long gesantGroesse = verzeichnisDurchsuchen(verzeichnisEingabe, extensionEingabe);

// //Ausgabe des Ergebnisses
// cout << "Gesamtverbrauch: " << gesamtGroesse << " Bytes" << endl;

// return 0;

// #include <iostream>
// #include <map>

// using namespace std;

// int main() {
//     //Zeichenhäufigkeit speichern
//     map<char, int> zeichenHaeufigkeit;

//     //Zeile vom Benutzer einlesen
//     string zeile;
//     cout << "Bitte geben Sie eine Zeile ein: ";
//     getline(cin, zeile);

//     //Häufigkeit jedes Zeichens zählen
//     for (char zeichen : zeile) {
//         zeichenHaeufigkeit[zeichen]++;
//     }

//     //Ausgabe der Zeichenhäufigkeit
//     for (auto zeichenPaar : zeichenHaeufigkeit) {
//     cout << zeichenPaar.first << ": " << zeichenPaar.second << endl;
//     }

//     return 0;
// }
//Aufgabe 13.05.24 Monte Carlo
//#include <iostream>
//#include <cstdlib>
//#include <random>

//using namespace std;

//int main() {
    //Anzahl der zufälligen Punkte
  //  int num_points = 100000;

    //Zähler für Punkte im Kreis
    //int in_circle = 0;

    //Zufallsgenerator initialisieren
    //random_device rd;
    //mt19937 gen(rd());
    //uniform_real_distribution<> dis(0.0, 1.0);

    //Zufällige Punkte generieren und auswerten 
    //for (int i = 0; i < num_points; ++i) {
       // double x = dis(gen);
        //double y = dis(gen);

        //Abstand vom Kreismittelpunkt berechnen
        //double distance = sqrt(x * x + y * y);

        //Prüfen, ob der Punkt im Kreis liegt
        //if (distance <= 1.0) {
          //  in_circle++;
       // }
   // }

    //Berechnen von Pi
    //double pi_approx = 4.0 * ((double) in_circle / (double) num_points);

    //Ausgabe des Ergebnisses
    //cout << "Naeherungsweise Berechnung von Pi: " << pi_approx << endl;

   // return 0;
//}

// #include <iostream>
// #include <string>
// #include <stdexcept>

// using namespace std;

// int main() {
//     string eingabe;
//     int zahl;

//     cout << "Geben Sie eine Ganzzahl ein: ";
//     cin >> eingabe;

//     try {
//         zahl = stoi(eingabe);
//         cout << "Die eingebebene Zahl ist: " << zahl << endl;
//     } catch (const invalid_argument& e) {
//         cerr << "Fehler: Konvertierung fehlgeschlagen. Ungültige Eingabe." << endl;
//     }

//     return 0;
//}

//Fibonacci Programm

// #include <iostream>
// using namespace std;

// int main() {
//     int n;

//     cout << "Geben Sie eine positive Ganzzahl ein: ";
//     cin >> n;

//     if (n < 0) {
//         cerr << "Fehler: Ungültige Eingabe. n muss positiv sein." << endl;
//     }

//     cout << "Die Fibonacci-Folge bis n = " << n << ":" << endl;

//     for (int i = 0; i <= n; i++) {
//         //int fibonacci = fibonacci_iterative(i);
//         int fibonacci = fibonacci_recursive(i);

//         cout << fibonacci << " ";
//     }

//     cout << endl;

//     return 0;
// }

// #include <iostream>
// #include <string>

// using namespace std;

// void fix_string_length(string& s, string::size_type desired_length,char fill_char) {
//     if (s.length() > desired_length) {
//         s.resize(desired_length);
//     }

//     while (s.length() < desired_length) {
//         s += fill_char;
//     }
// }

// int main() {
//     string str = "Dies ist ein Teststring";
//     char fill = '-';

//     cout << "Originaler String: " << str << endl;

//     fix_string_length(str, 10, '*');

//     cout << "String nach Kürzen und Auffüllen: " << str << endl;

//     fix_string_length(str, 20, '.');

//     cout << "String nach Erweitern und Auffüllen: " << str << endl;
//     return 0;
// }

//String Container
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void input_string(vector<string>& container) {
    string input;
    cout << "Geben Sie einen String ein: ";
    cin >> input;
    container.push_back(input);
}

void print_strings(const vector<string>& container) {
    if (container.empty()) {
        cout << "Der Container ist leer." << endl;
        return;
    }

    cout << "Strings im Container:" << endl;
    for (const string& str : container) {
        cout << str << endl;
    }
}

void save_strings(const vector<string>& container, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const string& str : container) {
            file << str << endl;
        }
        file.close();
        cout << "Strings erfolgreich in Datei '" << filename << "' gespeichert." << endl;
    } else {
        cerr << "Fehler beim Öffnen der Datei '" << filename << "' ." << endl;
    }
}

void load_strings(vector<string>& container, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            container.push_back(line);
        }
        file.close();
        cout << "Strings erfolgreich aus Datei '" << filename << "' geladen." << endl;
    } else {
        cerr << "Fehler beim Öffnen der Datei '" << filename << "'." << endl;
    }
}

int main() {
    vector<string> string_container;
    string filename = "strings.txt";

    char choice;
    do {
        cout << "\nMenü:" << endl;
        cout << "e: Programm beenden" << endl;
        cout << "i: Neuen String eingeben" << endl;
        cout << "a: Alle Strings ausgeben" << endl;
        cout << "s: Strings in Datei speichern" << endl;
        cout << "l: Strings aus Datei laden" << endl;
        cout << "Ihre Wahl: ";
        cin >> choice;

        switch (choice) {
            case 'e':
            cout << "Programm beendet." << endl;
            break;
            case 'i':
            input_string(string_container);
            break;
            case 'a':
            print_strings(string_container);
            case 's':
            save_strings(string_container, filename);
            break;
            case 'l':
            load_strings(string_container, filename);
            break;
            default:
            cout << "Ungültige Eingabe. Bitte wählen Sie eine Option aus dem Menü." << endl;
        }
    } while (choice != 'e');

    return 0;
}
