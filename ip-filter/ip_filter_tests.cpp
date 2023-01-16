#include "ip_filter_lib.h"
#include "gtest/gtest.h"

TEST(LexacalSortTest, testSort)
{
    std::vector<std::vector<std::string>> testingVector = {{"4", "1", "1", "4"},
                                                           {"5", "2", "1", "2"},
                                                           {"5", "1", "1", "2"},
                                                           {"5", "2", "2", "2"},
                                                           {"1", "1", "1", "3"}};

    std::vector<std::vector<std::string>> resultVector = {{"5", "2", "2", "2"},
                                                          {"5", "2", "1", "2"},
                                                          {"5", "1", "1", "2"},
                                                          {"4", "1", "1", "4"},
                                                          {"1", "1", "1", "3"}};

    //lexicalSort(testingVector);

    EXPECT_EQ(testingVector, resultVector);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
