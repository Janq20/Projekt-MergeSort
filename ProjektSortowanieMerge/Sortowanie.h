#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Sortowanie {
public:
    // Metoda publiczna
    void sortuj(std::vector<T>& tablica) {
        if (tablica.size() <= 1) return;
        sortujRekurencyjnie(tablica, 0, static_cast<int>(tablica.size()) - 1);
    }

private:
    // Metoda rekurencyjna
    void sortujRekurencyjnie(std::vector<T>& tablica, int lewy, int prawy) {
        if (lewy < prawy) {
            int srodek = lewy + (prawy - lewy) / 2;
            sortujRekurencyjnie(tablica, lewy, srodek);
            sortujRekurencyjnie(tablica, srodek + 1, prawy);
            scalaj(tablica, lewy, srodek, prawy);
        }
    }

    // Metoda scalajaca
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
            } else {
                tablica[k] = P[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            tablica[k] = L[i];
            i++; k++;
        }
        while (j < n2) {
            tablica[k] = P[j];
            j++; k++;
        }
    }
};