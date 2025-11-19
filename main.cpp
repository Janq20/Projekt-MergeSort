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

    // --- CZESC 1: Liczby Calkowite (INT) ---
    cout << "\n1. Testowanie dla typu INT:" << endl;
    vector<int> liczbyInt = { 38, 27, 43, 3, 9, 82, 10 };
    Sortowanie<int> sorterInt;

    cout << "Przed sortowaniem: ";
    wypiszTablice(liczbyInt);

    sorterInt.sortuj(liczbyInt);

    cout << "Po sortowaniu:     ";
    wypiszTablice(liczbyInt);

    return 0;
}