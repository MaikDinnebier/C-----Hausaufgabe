#include <iostream>
#include <fstream>
#include <string>

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

    //double einlesen
    double zahl1, zahl2;
    std::cout << "Erste Zahl: ";
    std::cin >> zahl1;
    if (std::cin.fail()) {
        std::cerr << "Fehler: Falsche Eingabe bei erster Zahl!" << std::endl;
        return 1;
    }
    std::cout << "Zweite Zahl: ";
    std::cin >> zahl2;
    if (std::cin.fail()) {
        std::cerr << "Fehler: Falsche Eingabe bei zweiter Zahl!" << std::endl;
        return 1;
    }

    //Logdatei schließen
    log.close();

    return 0;
}