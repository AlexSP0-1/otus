#include "ip_filter_lib.h"
#include "gtest/gtest.h"

TEST(sortTest, testSort)
{
    std::string ip1_str = "1.1.1.2";
    std::string ip2_str = "1.1.1.3";
    std::string ip3_str = "1.2.1.3";
    std::string ip4_str = "2.2.1.3";

    std::vector<ip_address> testVector;

    ip_address currentIp;
    currentIp.ip = inet_addr(ip1_str.c_str());
    testVector.push_back(currentIp);

    currentIp.ip = inet_addr(ip2_str.c_str());
    testVector.push_back(currentIp);

    currentIp.ip = inet_addr(ip3_str.c_str());
    testVector.push_back(currentIp);

    currentIp.ip = inet_addr(ip4_str.c_str());
    testVector.push_back(currentIp);

    std::vector<ip_address> resultVector;

    currentIp.ip = inet_addr(ip4_str.c_str());
    resultVector.push_back(currentIp);

    currentIp.ip = inet_addr(ip3_str.c_str());
    resultVector.push_back(currentIp);

    currentIp.ip = inet_addr(ip2_str.c_str());
    resultVector.push_back(currentIp);

    currentIp.ip = inet_addr(ip1_str.c_str());
    resultVector.push_back(currentIp);

    sortIp(testVector);

    EXPECT_EQ(testVector, resultVector);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
