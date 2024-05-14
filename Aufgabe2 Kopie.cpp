#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        char ziffer;
        cout << "Bitte geben Sie eine Ziffer ein: ";
        cin >> ziffer;

        if (!cin.good() || !isdigit(ziffer)) {
            break;
        }

        switch (ziffer)
        {
        case '0':
            cout << "null" << endl;
            break;
        case '1':
        cout << "eins" << endl;
        break;
        case '2':
        cout << "zwei" << endl;
        break;
        case '3':
        cout << "drei" << endl;
        break;
        case '4':
        cout << "vier" << endl;
        break;
        case '5':
        cout << "fünf" << endl;
        break;
        case '6':
        cout << "sechs" << endl;
        break;
        case '7':
        cout << "sieben" << endl;
        break;
        case '8':
        cout << "acht" << endl;
        break;
        case '9':
        cout << "neun" << endl;
        break;
        default:
        break;
        }
    }

    cout << "Ende" << endl;
    return 0;
}