#include <iostream>
#include <string>
#include <vector>

#include <memory>
#include <stdlib.h>

#include <arpa/inet.h>
#include <fstream>
#include <iostream>

#include "ip_filter_lib.h"

int main(int, char const *[])
{
    std::string f("1.2.1.1");
    std::string d("2.1.1.1");
    ip_address currentIp1;
    ip_address currentIp2;
    currentIp1.ip = inet_addr(f.c_str());
    currentIp2.ip = inet_addr(d.c_str());

    currentIp1.ip = currentIp2.ip;
    currentIp2.ip = currentIp1.ip;

    try
    {
        std::vector<ip_address> ip_pool;

        for (std::string line; std::getline(std::cin, line);)
        {
            std::string v = splitLine(line, '\t');

            if (!validateIpAddress(v))
            {
                std::cout << "String:" << v << " is not a valid IP address!" << std::endl;
                continue;
            }

            ip_address currentIp;
            currentIp.ip = inet_addr(v.c_str());

            ip_pool.push_back(currentIp);
        }

        sortIp(ip_pool);
        printIpVector(ip_pool);

        auto printByMask = [](std::vector<ip_address> ips, std::vector<int> mask) {
            auto byMaskResult = getIpByMask(ips, mask);
            printIpVector(byMaskResult);
        };

        printByMask(ip_pool, {1, -1, -1, -1});

        printByMask(ip_pool, {46, 70, -1, -1});

        auto resultByByte = getIpByByte(ip_pool, 46);
        printIpVector(resultByByte);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
