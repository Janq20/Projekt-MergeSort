#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Sortowanie {
public:
    void sortuj(std::vector<T>& tablica) {
        // TODO
    }

private:
    void sortujRekurencyjnie(std::vector<T>& tablica, int lewy, int prawy) {
        // TODO
    }

    // Implementacja scalania (Merge)
    void scalaj(std::vector<T>& tablica, int lewy, int srodek, int prawy) {
        int n1 = srodek - lewy + 1;
        int n2 = prawy - srodek;

        std::vector<T> L(n1);
        std::vector<T> P(n2);

        for (int i = 0; i < n1; i++) L[i] = tablica[lewy + i];
        for (int j = 0; j < n2; j++) P[j] = tablica[srodek + 1 + j];

        int i = 0, j = 0, k = lewy;
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
        while (i < n1) { tablica[k] = L[i]; i++; k++; }
        while (j < n2) { tablica[k] = P[j]; j++; k++; }
    }
};