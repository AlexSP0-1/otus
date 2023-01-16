#include "ip_filter_lib.h"

#include <arpa/inet.h>

std::string splitLine(const std::string &str, char d)
{
    std::string::size_type stop = str.find_first_of(d);

    return str.substr(0, stop);
}

void printIpVector(std::vector<std::string> &ipVector)
{
    std::for_each(ipVector.begin(), ipVector.end(), [&](std::string &currentIp) {
        std::cout << currentIp << std::endl;
        ;
    });
}

void printIpVector(std::vector<ip_address> &ipVector)
{
    std::for_each(ipVector.begin(), ipVector.end(), [&](ip_address &currentIp) {
        struct in_addr my_addr;

        my_addr.s_addr = currentIp.ip;

        std::cout << inet_ntoa(my_addr) << std::endl;
        ;
    });
}
