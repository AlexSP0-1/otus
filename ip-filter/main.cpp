#include <iostream>
#include <string>
#include <vector>

#include <memory>
#include <stdlib.h>

#include <fstream>
#include <iostream>

#include "ip_filter_lib.h"

int main(int, char const *[])
{
    try
    {
        std::vector<std::vector<std::string>> ip_pool;

        std::ifstream file("ip_filter.tsv");

        for (std::string line; std::getline(file, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        auto getAndPrintByMask = [](std::vector<std::vector<std::string>> ips,
                                    std::vector<int> mask) {
            auto taskResults = getIpsByMask(ips, mask);
            lexicalSort(*taskResults.get());
            printIpVector(*taskResults.get());
        };

        lexicalSort(ip_pool);
        printIpVector(ip_pool);

        getAndPrintByMask(ip_pool, {1, -1, -1, -1});
        getAndPrintByMask(ip_pool, {46, 70, -1, -1});

        auto task4Results = getIpsByAnyByte(ip_pool, 46);
        lexicalSort(*task4Results.get());
        printIpVector(*task4Results.get());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
