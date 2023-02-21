#include <gtest/gtest.h>
#include <iostream>

#include "ipprinters.h"

TEST(TestPrintString, SFINAE)
{
    std::ostringstream testStream;
    auto buffer = std::cout.rdbuf();
    std::cout.rdbuf(testStream.rdbuf());

    print_ip(std::string("1234qwert"));

    std::cout.rdbuf(buffer);

    ASSERT_EQ(testStream.str(), "1234qwert\n");
}

TEST(TestPrintIntegralTypes, SFINAE)
{
    std::ostringstream testStream;
    auto buffer = std::cout.rdbuf();
    std::cout.rdbuf(testStream.rdbuf());

    print_ip(char(-1));
    print_ip(short(0));
    print_ip(2130706433);
    print_ip(8875824491850138409L);

    std::cout.rdbuf(buffer);

    ASSERT_EQ(testStream.str(), "255\n0.0\n127.0.0.1\n123.45.67.89.101.112.131.41\n");
}

TEST(TestPrintVector, SFINAE)
{
    std::ostringstream testStream;
    auto buffer = std::cout.rdbuf();
    std::cout.rdbuf(testStream.rdbuf());

    print_ip(std::vector{1, 2, 3, 4});

    std::cout.rdbuf(buffer);

    ASSERT_EQ(testStream.str(), "1.2.3.4\n");
}

TEST(TestPrintList, SFINAE)
{
    std::ostringstream testStream;
    auto buffer = std::cout.rdbuf();
    std::cout.rdbuf(testStream.rdbuf());

    print_ip(std::list{111, 222, 333, 444});

    std::cout.rdbuf(buffer);

    ASSERT_EQ(testStream.str(), "111.222.333.444\n");
}

TEST(TestPrintTuple, SFINAE)
{
    std::ostringstream testStream;
    auto buffer = std::cout.rdbuf();
    std::cout.rdbuf(testStream.rdbuf());

    print_ip(std::make_tuple(111, 222, 333, 444));

    std::cout.rdbuf(buffer);

    ASSERT_EQ(testStream.str(), "111.222.333.444\n");
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
