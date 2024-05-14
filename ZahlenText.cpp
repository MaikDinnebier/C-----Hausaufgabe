#include <iostream>
#include <string>

using namespace std;

string zahlZuText(int zahl) {
    switch (zahl) {
        case 1:
            return "eins";
        case 2:
            return "zwei";
        case 3:
            return "drei";
        case 4:
            return "vier";
        case 5:
            return "fuenf";
        default:
            throw invalid_argument("Ungültige Zahl: " + to_string(zahl));
    }
}

int main() {
    for (int i = 1; i <= 5; ++i) {
    try {
        string text =  zahlZuText(i);
        cout << i << " -> " << text << endl;
    } catch (const invalid_argument& e) {
        cerr << "Fehler: " << e.what() << endl;
    }    
}
return 0;
}