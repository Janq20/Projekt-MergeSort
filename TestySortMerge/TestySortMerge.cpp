#include <gtest/gtest.h>
#include <vector>
#include "../ProjektSortowanieMerge/Sortowanie.h" 

using namespace std;

TEST(TestySortowania, SortujeOdwrotnaKolejnosc) {
    std::vector<int> tablica = { 5, 4, 3, 2, 1 };
    std::vector<int> oczekiwana = { 1, 2, 3, 4, 5 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}