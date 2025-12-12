# 🔀 Projekt: Merge Sort (C++)

Projekt zawiera **implementację algorytmu sortowania przez scalanie (Merge Sort)** w postaci **szablonu klasy C++**, wraz z programem demonstracyjnym oraz rozbudowanym zestawem **testów jednostkowych Google Test**.  
Kod jest opisany w stylu dokumentacji technicznej (Doxygen) i przygotowany tak, aby łatwo rozszerzać go o nowe typy danych i scenariusze testowe.

---

## 💡 Opis Projektu

**Merge Sort** to klasyczny algorytm sortowania oparty o strategię *„dziel i zwyciężaj”*.  
Działa poprzez:

1. **Dzielenie** danych na coraz mniejsze podtablice aż do jednoelementowych fragmentów.
2. **Scalanie** posortowanych części w większe fragmenty, aż do uzyskania w pełni posortowanej tablicy.

W projekcie algorytm został zaimplementowany jako:

- **szablon klasy `Sortowanie<T>`** (możliwość sortowania `int`, `double`, itd.),
- algorytm sortuje **in-place** (modyfikuje wektor bez tworzenia nowego “wynikowego” interfejsu),
- scalanie realizowane jest z użyciem **wektorów pomocniczych** dla lewej i prawej części.

---

## ✨ Główne Cechy

* **Szablon C++ (`template`)** – sortowanie dowolnego typu `T`, który obsługuje operator `<=`.
* **Czytelna implementacja Merge Sort** – podział rekurencyjny + scalanie.
* **Program demonstracyjny (`ProjektSortowanieMerge.cpp`)** – pokaz działania algorytmu na `int` i `double`.
* **14 testów jednostkowych w Google Test** – w tym przypadki brzegowe i większe zbiory danych.
* **Dokumentacja Doxygen w komentarzach** – gotowe pod generowanie PDF/HTML.

---

## 🧪 Testy Jednostkowe (Google Test)

Plik: `TestySortMerge.cpp`

Zestaw testów obejmuje m.in.:

- tablicę już posortowaną,
- tablicę odwróconą,
- losowy układ danych,
- liczby ujemne, dodatnie i mieszane,
- duplikaty (pozytywne i negatywne),
- przypadki brzegowe (pusta tablica, 1 element, 2 elementy),
- test większej tablicy (105 elementów),
- test “mieszany + duplikaty” dla >100 elementów.

---

## 📁 Struktura projektu

```
.
├── ProjektSortowanieMerge.cpp      # Program demonstracyjny (main)
├── ProjektSortowanieMerge/
│   └── Sortowanie.h                # Implementacja szablonu Merge Sort
└── Testy/
    └── TestySortMerge.cpp          # Testy jednostkowe Google Test
```

> Uwaga: nazwy folderów mogą się różnić w zależności od Twojej struktury repo, ale kluczowe pliki to `Sortowanie.h`, `ProjektSortowanieMerge.cpp`, `TestySortMerge.cpp`.

---

## 🛠 Jak uruchomić (kompilacja)

### 1) Program demonstracyjny

**Linux/macOS (g++):**
```bash
g++ -std=c++17 -O2 -I. ProjektSortowanieMerge.cpp -o mergesort_demo
./mergesort_demo
```

**Windows (MinGW):**
```bash
g++ -std=c++17 -O2 -I. ProjektSortowanieMerge.cpp -o mergesort_demo.exe
mergesort_demo.exe
```

---

### 2) Testy (Google Test)

Wymagane: skonfigurowane Google Test (np. przez CMake albo ręcznie jako biblioteki).

Przykładowo (poglądowo):
```bash
g++ -std=c++17 -I. -I<gtest_include> TestySortMerge.cpp <gtest_libs> -o mergesort_tests
./mergesort_tests
```

Najwygodniej zbudować testy przez **CMake**, jeśli repo ma konfigurację (jeśli nie ma – mogę Ci ją przygotować).

---

## 📖 Jak działa algorytm (w skrócie)

W `Sortowanie.h`:

- `sortuj(vector<T>&)` to publiczny punkt wejścia.
- `sortujRekurencyjnie(...)` dzieli zakres na dwa podzakresy.
- `scalaj(...)` łączy dwie posortowane połówki w całość.

Złożoności:
- **Czas:** `O(n log n)`
- **Pamięć:** `O(n)` (bufory pomocnicze w scalaniu)

---

## ✅ Autor

- **Janq20**

---
## 🤝 Rozwój / Pomysły na ulepszenia

* dodać test stabilności sortowania (np. sortowanie par `(klucz, indeks)`),
* dodać benchmark (Google Benchmark albo prosty pomiar czasu),
* wersja iteracyjna Merge Sort (bez rekurencji),
