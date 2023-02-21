#include <gtest/gtest.h>
#include <iostream>

#include "ipprinters.h"

TEST(TestPrintIntegralTypes, SFINAE)
{
    std::ostringstream testStream;
    auto buffer = std::cout.rdbuf();
    std::cout.rdbuf(testStream.rdbuf());

    print_ip(std::string("1234qwert"));

    std::cout.rdbuf(buffer);

    ASSERT_EQ(testStream.str(), "1234qwert\n");
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
