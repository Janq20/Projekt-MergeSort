#include <gtest/gtest.h>
#include <vector>
#include "../ProjektSortowanieMerge/Sortowanie.h" 
using namespace std;
TEST(TestySortowania, MieszaneUjemneIDodatnie) {
    std::vector<int> tablica = { -5, 2, -1, 0, 10 };
    std::vector<int> oczekiwana = { -5, -1, 0, 2, 10 };
    Sortowanie<int> sorter;
    sorter.sortuj(tablica);

    EXPECT_EQ(tablica, oczekiwana);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}