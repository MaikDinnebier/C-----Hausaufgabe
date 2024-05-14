#include <iostream>
#include <fstream>
#include <string>
#include <format>


int main() {
    //Logdatei öffnen
    std::string logfile;
    std::cout << "Logdatei-Name: ";
    std::cin >> logfile;
    std::ofstream log(logfile);
    if (!log.is_open()) {
        std::cerr << "Fehler: konnte Logdatei nicht öffnen!" << std::endl;
        return 1;
    }

    //Zahlen einlesen
    double zahl1, zahl2;
    std::cout << "Erste Zahl: ";
    std:: cin >> zahl1;
    if (std::cin.fail()) {
        std::cerr << "Fehler: Falsche Eingabe bei erster Zahl1!" << std::endl;
        return 1;
    }
    std::cout << "Zweite Zahl: ";
    std::cin >> zahl2;
    if (std::cin.fail()) {
        std::cerr << "Fehler: Falsche Eingabe bei zweiter Zahl!" << std::endl;
        return 1;
    }

    //Summe berechnen und ausgeben
    double summe = zahl1 + zahl2;
    std::cout << std::format("Summe: {}\n", summe);
    log << std::format("Summe von {} und {}: {}\n", zahl1, zahl2, summe);

    //Logdatei schließen
    log.close();

    return 0;
}