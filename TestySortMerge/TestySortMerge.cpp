#include <gtest/gtest.h>
#include <vector>
#include "../ProjektSortowanieMerge/Sortowanie.h" 

using namespace std;

// 3. Sprawdzenie sortowania losowej listy
TEST(TestySortowania, SortujeLosowaTablice) {
    std::vector<int> tablica = { 12, 7, 14, 9, 10, 11 };
    std::vector<int> oczekiwana = { 7, 9, 10, 11, 12, 14 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}