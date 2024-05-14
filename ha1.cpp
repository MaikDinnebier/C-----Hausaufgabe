#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// 1: Erzeuge eine Funktion void bubble(), die ein Array von Zahlen sortiert.
//! Der BubbleSort (https://en.wikipedia.org/wiki/Bubble_sort) hat eine
//! durchschnittliche und schlechteste Laufzeitkomplexität von O(n^2), was dazu
//! führt, dass es bei vielen Elementen langsam ist. Unten befinden sich drei
//! weitere Sortieralgorithmen: MergeSort, QuickSort und HeapSort.
void bubble(int numbers[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
}

int suchen(const vector<int>& v, int size, int key) {
    auto it = find(v.begin(), v.end(), key);
    return (it != v.end()) ? distance(v.begin(), it) : -1;
}

// 3: Schreibe eine Funktion int duplikateEntfernen (gibt neue Größe zurück),
// die alle Einträge in einem Array entfernt, die mehrfach enthalten sind.
int removeDuplicatesSorted(int arr[], int n) {
    if (n == 0 || n == 1) return n;

    int j = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1]) arr[j++] = arr[i];

    arr[j++] = arr[n - 1];

    return j;
}

int removeDuplicatesUnsorted(int arr[], int n) {
    if (n == 0 || n == 1) return n;

    int* temp = new int[n];

    int j = 0;

    for (int i = 0; i < n; i++) {
        int k;
        for (k = 0; k < j; k++) {
            if (arr[i] == temp[k]) break;
        }
        if (k == j) {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    delete temp;

    return j;
}

// 5: Schreibe eine Funktion int suchen(), die eine sequentielle Suche eines
// Bereiches durchführt.
int sequentialSearch(int array[], int arraySize, int targetValue) {
    for (int index = 0; index < arraySize; index++) {
        if (array[index] == targetValue) {
            return index;
        }
    }
    return -1;
}

// 9: Implementiere eine neue Suche auf der Basis des gewählten Ansatzes.
int binarySearch(int array[], int leftIndex, int rightIndex, int targetValue) {
    while (leftIndex <= rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (array[middleIndex] == targetValue) return middleIndex;

        if (array[middleIndex] < targetValue)
            leftIndex = middleIndex + 1;
        else
            rightIndex = middleIndex - 1;
    }

    return -1;
}

int main() {
    srand(time(0));

    // 2: Erzeuge ein Array mit 10 Zufallszahlen (0..100), die sortiert werden.
    // 6: Initialisiere den Bereich mit 10 Zufallszahlen (0..100).
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101;
    }

    bubble(arr, 10);

    // 4: Initialisiere ein separates Array mit 10 Zufallszahlen im Bereich
    // 0..10 und entferne Duplikate.
    int arr0to10[10];
    for (int i = 0; i < 10; i++) {
        arr0to10[i] = rand() % 11;
    }

    bubble(arr0to10, 10);
    int newSize0to10 = removeDuplicatesSorted(arr0to10, 10);

    cout << "Array mit Zahlen von 0 bis 10 nach Entfernen von Duplikaten: ";
    for (int i{0}; i < newSize0to10; i++) {
        cout << arr0to10[i] << " ";
    }
    cout << "\nNeue Größe: " << newSize0to10 << endl;

    // 7: Was fällt auf? Die sequentielle Suche durchläuft das gesamte Array und
    // ist somit bei großen Datenmengen ineffizient. Diese Suche hat eine
    // Laufzeit von O(n), da jedes Element des Arrays überprüft werden muss

    // 8: Man könnte die Suche verbessern, indem man eine binäre Suche
    // verwendet. Im Gegensatz zu der sequenziellen Suche, hat die binäre Suche
    // eine Laufzeit von O(log n), was dazu führt, dass es schneller ist. Eine
    // Voraussetzung von der binären Suche ist jedoch, dass das Array vorher
    // sortiert werden muss. Merkhilfe:
    // https://www.geeksforgeeks.org/linear-search-vs-binary-search/

    return 0;
}

/* QuickSort --- https://wikipedia.org/wiki/Quicksort
| Fall   | Laufzeitkomplexität |
|--------|---------------------|
| Beste  | O(n log n)          |
| Durchschnitt | O(n log n)    |
| Schlechteste | O(n^2)        |
*/
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partitionQS(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partitionQS(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* MergeSort --- https://wikipedia.org/wiki/MergeSort
| Fall   | Laufzeitkomplexität |
|--------|---------------------|
| Beste  | O(n log n)          |
| Durchschnitt | O(n log n)    |
| Schlechteste | O(n log n)    |
*/
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* HeapSort --- https://wikipedia.org/wiki/HeapSort
| Fall   | Laufzeitkomplexität |
|--------|---------------------|
| Beste  | O(n log n)          |
| Durchschnitt | O(n log n)    |
| Schlechteste | O(n log n)    |
*/
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;

    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
