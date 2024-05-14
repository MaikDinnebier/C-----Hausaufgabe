#include <iostream>
#include <vector>

using namespace std;

int duplikateEntfernen(vector<int>& arr) {
    //Sortiere das Array in aufsteigender Reihenfolge 
    sort(arr.begin(), arr.end());

    //Iterator zum Duchlaufen des Arrays
    auto it = arr.begin();

    //Schleife über alle Elemente des Arrays
    while (it != arr.end()) {
        //Finde den nächsten Eintrag mit demselben Wert
        auto next_it = find(it + 1, arr.end(), *it);

        //Wenn ein Duplikat gefunden wird, lösche es
        if (next_it != arr.end()) {
            arr.erase(next_it);
        }

        //Bewege den Iterator zum nächsten Element
        it++;
    }

    //Gib die neue Größe des Arrays zurück
    return arr.size();
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5 };

    int neueGroesse = duplikateEntfernen(arr);
    cout<< "Array nach Entfernen von Duplikaten: \n";
    for (int i = 0; i < neueGroesse; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}