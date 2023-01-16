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
    try
    {
        std::vector<ip_address> ip_pool;

        std::ifstream file("ip_filter.tsv");

        for (std::string line; std::getline(file, line);)
        {
            std::string v = splitLine(line, '\t');

            ip_address currentIp;
            currentIp.ip = inet_addr(v.c_str());

            ip_pool.push_back(currentIp);
        }

        printIpVector(ip_pool);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
