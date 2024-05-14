#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[]) {
    //Prüfen auf Korrekte Anzahl der Argumente
    if (argc != 2) {
        std::cerr << "Falsche Anzahl an Argumenten!" << std::endl;
        std::cerr << "Verwendung: hexdump <datei>" << std::endl;
        return 1;
    }

    //Datei öffnen
    std::ifstream infile(argv[1], std::ios::binary);

    //Prüfen auf Fehler beim Öffnen der Datei
    if (!infile.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << argv[1] << std::endl;
        return 1;
    }

    //Byte für Byte lesen und als Hexadezimalzahl ausgeben
    char byte;
    while (infile.read(&byte, 1)) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";
    }

    //datei schließen
    infile.close();

    return 0;
}


//Aufgabe 5: Die Datentypen von std::cin und std::cout sind:
//std::cin: Ein Objekt vom Typ std::istream. Ein istream-Objekt ist ein Eingabestream, der Daten aus einem Eingabegerät wie der Tastatur liest.
//std::cout: Ein Objekt vom Typ std::ostream. Ein ostream-Objekt ist ein Ausgabestream, der Daten an ein Ausgabegerät wie die Konsole oder eine Datei schreibt.
//Sowohl std::istream als auch std::ostream sind Teil der C++ Standard Template Library (STL) und bieten generische Schnittstellen für die Eingabe und Ausgabe von Daten verschiedener Datentypen.
//Es ist wichtig zu beachten, dass std::cin und std::cout keine Datentypen im eigentlichen Sinne sind, sondern Objekte vordefinierter Typen. Sie stellen Streams dar, die zum Lesen bzw. Schreiben von Daten verwendet werden.
//Die eigentlichen Datentypen, die mit std::cin und std::cout verwendet werden können, hängen von der Art der Daten ab, die Sie ein- oder ausgeben möchten. Zum Beispiel können Sie Ganzzahlen, Gleitkommazahlen, Zeichenketten und andere Datentypen lesen und schreiben.
//Zusammenfassung:
//std::cin ist ein std::istream-Objekt für die Eingabe von Daten.
//std::cout ist ein std::ostream-Objekt für die Ausgabe von Daten.
//Die Datentypen, die mit std::cin und std::cout verwendet werden können, variieren je nach den gelesenen oder geschriebenen Daten.
