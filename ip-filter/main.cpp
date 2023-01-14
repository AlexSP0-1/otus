#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <QCoreApplication>

#include <memory>
#include <stdlib.h>

#include <fstream>
#include <iostream>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop  = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop  = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

bool isIp1GreaterIp2(std::vector<std::string> &ip1, std::vector<std::string> &ip2)
{
    for (size_t position = 0; position < ip1.size(); position++)
    {
        int ip1Part = atoi(ip1.at(position).c_str());
        int ip2Part = atoi(ip2.at(position).c_str());

        if (ip1Part > ip2Part)
        {
            return true;
        }
        if (ip1Part < ip2Part)
        {
            return false;
        }
    }

    return false;
}

void lexicalSort(std::vector<std::vector<std::string>> &ips, bool invertFlag)
{
    //buble sort
    for (size_t j = ips.size() - 1; j > 0; j--)
    {
        for (size_t i = 0; i < j; i++)
        {
            bool isGreater = isIp1GreaterIp2(ips.at(i), ips.at(i + 1));

            if (invertFlag)
            {
                isGreater = !isGreater;
            }

            if (isGreater)
            {
                std::swap(ips.at(i), ips.at(i + 1));
            }
        }
    }
}

void printIpVector(std::vector<std::vector<std::string>> &ipVector)
{
    for (std::vector<std::vector<std::string>>::const_iterator ip = ipVector.cbegin();
         ip != ipVector.cend();
         ++ip)
    {
        for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend();
             ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

std::unique_ptr<std::vector<std::vector<std::string>>> getIpsByMask(
    std::vector<std::vector<std::string>> ips, std::vector<int> &mask)
{
    std::vector<std::vector<std::string>> newVector(ips);

    for (size_t position = 0; position < mask.size(); position++)
    {
        if (mask[position] != -1)
        {
            for (std::vector<std::vector<std::string>>::iterator it = newVector.begin();
                 it != newVector.end();)
            {
                int byteInPositiond = atoi(it->at(position).c_str());
                if (byteInPositiond != mask.at(position))
                {
                    newVector.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
    }

    return std::move(std::make_unique<std::vector<std::vector<std::string>>>(newVector));
}

std::unique_ptr<std::vector<std::vector<std::string>>> getIpsByAnyByte(
    std::vector<std::vector<std::string>> ips, int byte)
{
    std::vector<std::vector<std::string>> newVector;

    for (std::vector<std::vector<std::string>>::iterator it = ips.begin(); it != ips.end();)
    {
        for (std::vector<std::string>::iterator itt = it->begin(); itt != it->end();)
        {
            if (byte == atoi((*itt).c_str()))
            {
                newVector.emplace_back(*it);
            }
            itt++;
        }
        it++;
    }

    return std::move(std::make_unique<std::vector<std::vector<std::string>>>(newVector));
}

int main(int argc, char const *argv[])
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

        lexicalSort(ip_pool, true);

        printIpVector(ip_pool);

        std::vector<int> mask2 = {1, -1, -1, -1};
        auto task2Results      = getIpsByMask(ip_pool, mask2);
        lexicalSort(*task2Results.get(), true);
        printIpVector(*task2Results.get());

        std::vector<int> mask3 = {46, 70, -1, -1};
        auto task3Results      = getIpsByMask(ip_pool, mask3);
        lexicalSort(*task3Results.get(), true);
        printIpVector(*task3Results.get());

        auto task4Results = getIpsByAnyByte(ip_pool, 46);
        lexicalSort(*task4Results.get(), true);
        printIpVector(*task4Results.get());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
