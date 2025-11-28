#include <gtest/gtest.h>
#include <vector>
#include "../ProjektSortowanieMerge/Sortowanie.h" 

using namespace std;

// 1. Pierwszy test sortowania
TEST(TestySortowania, ZachowujePosortowana) {
    std::vector<int> tablica = { 1, 2, 3, 4, 5 };
    std::vector<int> oczekiwana = { 1, 2, 3, 4, 5 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 2. Sortowanie odwrotnej tablicy
TEST(TestySortowania, SortujeOdwrotnaKolejnosc) {
    std::vector<int> tablica = { 5, 4, 3, 2, 1 };
    std::vector<int> oczekiwana = { 1, 2, 3, 4, 5 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 3. Sortowanie losowej tablicy liczb
TEST(TestySortowania, SortujeLosowaTablice) {
    std::vector<int> tablica = { 12, 7, 14, 9, 10, 11 };
    std::vector<int> oczekiwana = { 7, 9, 10, 11, 12, 14 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 4. Sortowanie tablicy tylko z liczbami ujemnymi
TEST(TestySortowania, SortujeTylkoUjemne) {
    std::vector<int> tablica = { -10, -2, -30, -5 };
    std::vector<int> oczekiwana = { -30, -10, -5, -2 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 5. Sortowanie tablicy z liczbami ujemnymi i dodatnimi
TEST(TestySortowania, SortujeMieszaneUjemneIDodatnie) {
    std::vector<int> tablica = { -5, 2, -1, 0, 10 };
    std::vector<int> oczekiwana = { -5, -1, 0, 2, 10 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 6. Obsługuje pustą tablicę bez rzucania wyjątkiem
TEST(TestySortowania, ObslugaPustejTablicy) {
    std::vector<int> tablica = {};
    std::vector<int> oczekiwana = {};
    Sortowanie<int> sorter;
    // ASSERT_NO_THROW sprawdza, czy funkcja nie powoduje crasha
    ASSERT_NO_THROW(sorter.sortuj(tablica));
    EXPECT_EQ(tablica, oczekiwana);
}
// 7. Nie zmienia tablicy, która zawiera tylko jeden element
TEST(TestySortowania, JedenElement) {
    std::vector<int> tablica = { 42 };
    std::vector<int> oczekiwana = { 42 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 8. Sortowanie tablicy z duplikatami liczb
TEST(TestySortowania, ObslugaDuplikatow) {
    std::vector<int> tablica = { 5, 1, 5, 3, 1 };
    std::vector<int> oczekiwana = { 1, 1, 3, 5, 5 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 9. Sortowanie tablicy ujemną z duplikatami
TEST(TestySortowania, UjemneZDuplikatami) {
    std::vector<int> tablica = { -5, -1, -5, -3, -1 };
    std::vector<int> oczekiwana = { -5, -5, -3, -1, -1 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 10. Sortowanie tablicy z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(TestySortowania, MieszaneZDuplikatami) {
    std::vector<int> tablica = { -2, 2, 0, -2, 5, 5 };
    std::vector<int> oczekiwana = { -2, -2, 0, 2, 5, 5 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 11. Sortowanie tablicy zawierającej tylko dwa elementy w kolejności rosnącej
TEST(TestySortowania, DwaElementyRosnaco) {
    std::vector<int> tablica = { 10, 20 };
    std::vector<int> oczekiwana = { 10, 20 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}
// 12. Sortowanie dużej tablicy zawierającej ponad 100 elementów
TEST(TestySortowania, DuzaTablica) {
    std::vector<int> tablica;
    for (int i = 105; i > 0; i--) {
        tablica.push_back(i);
    }

    Sortowanie<int> sorter;
    sorter.sortuj(tablica);

    EXPECT_EQ(tablica.size(), 105);
    EXPECT_EQ(tablica[0], 1);     
    EXPECT_EQ(tablica[104], 105); 
    for (size_t i = 0; i < tablica.size() - 1; ++i) {
        EXPECT_LE(tablica[i], tablica[i + 1]);
    }
}
// 13. Duża tablica (>100 el) z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(TestySortowania, DuzaTablicaMieszanaZDuplikatami) {
    std::vector<int> tablica;
    for (int i = 0; i < 50; i++) tablica.push_back(i);
    for (int i = 0; i < 50; i++) tablica.push_back(-i);
    tablica.push_back(0);
    tablica.push_back(5);

    Sortowanie<int> sorter;
    sorter.sortuj(tablica);

    EXPECT_GT(tablica.size(), 100);
    for (size_t i = 0; i < tablica.size() - 1; ++i) {
        EXPECT_LE(tablica[i], tablica[i + 1]);
    }
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}