#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Sortowanie {
public:
    void sortuj(std::vector<T>& tablica);

private:
    void sortujRekurencyjnie(std::vector<T>& tablica, int lewy, int prawy);
    void scalaj(std::vector<T>& tablica, int lewy, int srodek, int prawy);
};

// --- IMPLEMENTACJA PROGRAMU ---

// Funkcja scalajaca dwie posortowane podtablice
template <typename T>
void Sortowanie<T>::scalaj(std::vector<T>& tablica, int lewy, int srodek, int prawy) {
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;

    // Tablice tymczasowe
    std::vector<T> L(n1);
    std::vector<T> P(n2);

    // Kopiowanie danych do tablic tymczasowych
    for (int i = 0; i < n1; i++)
        L[i] = tablica[lewy + i];
    for (int j = 0; j < n2; j++)
        P[j] = tablica[srodek + 1 + j];

    // Scalanie tablic tymczasowych z powrotem do tablicy glownej
    int i = 0;
    int j = 0;
    int k = lewy;

    while (i < n1 && j < n2) {
        if (L[i] <= P[j]) {
            tablica[k] = L[i];
            i++;
        }
        else {
            tablica[k] = P[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostalych elementow L, jesli sa
    while (i < n1) {
        tablica[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozostalych elementow P, jesli sa
    while (j < n2) {
        tablica[k] = P[j];
        j++;
        k++;
    }
}

template <typename T>
void Sortowanie<T>::sortuj(std::vector<T>& tablica) {
}

template <typename T>
void Sortowanie<T>::sortujRekurencyjnie(std::vector<T>& tablica, int lewy, int prawy) {
}