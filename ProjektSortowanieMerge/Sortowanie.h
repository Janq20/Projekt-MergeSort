#pragma once
#include <vector>
#include <iostream>
template <typename T>
class Sortowanie {
public:
    void sortuj(std::vector<T>& tablica) {
        // Weryfikacja warunku brzegowego: tablice o rozmiarze 0 lub 1 s¹ z definicji posortowane.
        if (tablica.size() <= 1) return;
        sortujRekurencyjnie(tablica, 0, static_cast<int>(tablica.size()) - 1);
    }

private:
    // Prywatna metoda pomocnicza realizuj¹ca strategiê "Dziel"
    void sortujRekurencyjnie(std::vector<T>& tablica, int lewy, int prawy) {
        if (lewy < prawy) {
            int srodek = lewy + (prawy - lewy) / 2;

            // Rekurencyjne wywo³anie dla lewej po³owy zakresu
            sortujRekurencyjnie(tablica, lewy, srodek);

            // Rekurencyjne wywo³anie dla prawej po³owy zakresu
            sortujRekurencyjnie(tablica, srodek + 1, prawy);
            scalaj(tablica, lewy, srodek, prawy);
        }
    }

    // Metoda realizuj¹ca scalanie dwóch posortowanych podtablic w jedn¹ ca³oœæ.
    void scalaj(std::vector<T>& tablica, int lewy, int srodek, int prawy) {
        // Obliczenie rozmiarów podtablic lewej (n1) i prawej (n2)
        int n1 = srodek - lewy + 1;
        int n2 = prawy - srodek;
        std::vector<T> L(n1), P(n2);
        for (int i = 0; i < n1; i++) L[i] = tablica[lewy + i];
        for (int j = 0; j < n2; j++) P[j] = tablica[srodek + 1 + j];

        int i = 0; 
        int j = 0; 
        int k = lewy; 
        while (i < n1 && j < n2) {
            if (L[i] <= P[j]) {
                tablica[k++] = L[i++];
            }
            else {
                tablica[k++] = P[j++];
            }
        }
        while (i < n1) tablica[k++] = L[i++];
        while (j < n2) tablica[k++] = P[j++];
    }
};