#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    //Prüfen auf korrekte Anzahl der Argumente
    if (argc < 2 || argc > 3) {
        std::cerr << "Falsche Anzahl an Argumenten!" << std::endl;
        std::cerr << "Verwendung: echo <infile> [outfile]" << std::endl;
        return 1;
    }

    //Eingabe- und Ausgabedatei öffnen
    std::ifstream infile;
    std::ofstream outfile;

    if (argc == 3) {
        infile.open(argv[1]);
        outfile.open(argv[2]);
    }else {
        infile.open(argv[1]);
        std::ofstream outfile(std::cout);
    }

    //Prüfen auf Fehler beim Öffnen der Dateien
    if (!infile.is_open()) {
        std::cerr << "Fehler beim Öffnen der Eingabedatei: " << argv[1] << std::endl;
        return 1;
    }

    if (argc == 3 && !outfile.is_open()) {
        std::cerr << "Fehler beim Öfnnen der Ausgabedatei: " <<argv[2] << std::endl;
        return 1;
    }

    //Zeile für Zeile lesen und ausgeben
    std::string line;
    while (std::getline(infile, line)) {
        outfile << line << std::endl;
    }

    //Dateien schließen
    infile.close();
    outfile.close();
    return 0;
}