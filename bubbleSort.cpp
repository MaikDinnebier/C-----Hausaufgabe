#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    //Schleife über alle Elemente des Arrays
    for (int i = 0; i < n -1; i++) {
        //Schleife über alle Elemente bis zum aktuellen Element
        for (int j = 0; j < n - i -1; j++) {
            //Vergleiche benachbarte Elemente
            if (arr[j] < arr[j + 1]) {
                //Vertausche Elemente, wenn das linke Element größer ist als das rechte Element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsortierte Array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);

    cout << "\n\nSortiertes Array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}