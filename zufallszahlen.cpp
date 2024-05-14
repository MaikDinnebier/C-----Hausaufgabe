#include <iostream>
#include <random>
#include <vector>
#include <bubbleSort.h>

using namespace std;

void bubbleSort(vector<int>& arr) {
    //Schleife über alle Elemente des Arrays
    for (int i = 0; i < arr.size() - 1; j++) {
        //Schleife über alle Elemente bis zum aktuellen Element
        for(int j = 0; j < arr.size() - 1; j++) {
            //Vergleiche benachbarte Elemente
            if (arr[j] > arr[j + 1]) {
                //Vertausche Elemente, wenn das linke Element größer als ist das rechte Element
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Zufallszahlengenerator initialisieren
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100);

    //Vektor deklarieren
    vector<int> arr(10);

    //Zufallszahlen generieren und in Array speichern
    for (int i = 0; i < 10; i++) {
        arr[i] = dist(gen);
    }

    //Unsortiertes Array ausgeben
    cout << "Unsortiertes Array: \n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    //bubbleSort-Funktion aufrufen
    bubbleSort(arr);

    //Sortiertes Array ausgeben
    cout << "\n\nSortiertes Array: \n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}