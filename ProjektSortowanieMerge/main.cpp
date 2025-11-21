#include <iostream>
#include <vector>
#include "Sortowanie.h"

using namespace std;

// Funkcja pomocnicza do wyswietlania zawartosci wektora
template <typename T>
void wypiszTablice(const vector<T>& tablica) {
    for (const auto& element : tablica) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== PROJEKT: MERGE SORT ===" << endl;
    // TODO: Implementacja testow dla int i double
    return 0;
}