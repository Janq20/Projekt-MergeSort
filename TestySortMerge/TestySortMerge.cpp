#include <gtest/gtest.h>
#include <vector>
#include "../ProjektSortowanieMerge/Sortowanie.h" 

using namespace std;

// 4. Poprawnie sortuje tablicę tylko z liczbami ujemnymi
TEST(TestySortowania, SortujeTylkoUjemne) {
    std::vector<int> tablica = { -10, -2, -30, -5 };
    std::vector<int> oczekiwana = { -30, -10, -5, -2 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);
    EXPECT_EQ(tablica, oczekiwana);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}