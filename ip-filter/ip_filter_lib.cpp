#include "ip_filter_lib.h"

#include <arpa/inet.h>
#include <time.h>

std::string splitLine(const std::string &str, char d)
{
    std::string::size_type stop = str.find_first_of(d);

    return str.substr(0, stop);
}

void printIpVector(std::vector<ip_address> &ipVector)
{
    std::for_each(ipVector.begin(), ipVector.end(), [&](ip_address &currentIp) {
        struct in_addr my_addr;

        my_addr.s_addr = currentIp.ip;

        std::cout << inet_ntoa(my_addr) << std::endl;
    });
}

void sortIp(std::vector<ip_address> &ips)
{
    std::sort(ips.begin(), ips.end(), [](ip_address &ip1, ip_address &ip2) {
        for (size_t i = 0; i < sizeof(ip1.octets) / sizeof(ip1.octets[0]); i++)
        {
            if (ip1.octets[i] > ip2.octets[i])
            {
                return true;
            }
            if (ip1.octets[i] < ip2.octets[i])
            {
                return false;
            }
        }
        return false;
    });
}

void generateIpVector(std::vector<ip_address> &ips, int size)
{
    ips.clear();
    ips.reserve(size);

    //    srand(time(NULL));
    //    for(size_t i = 0; i < size; i++) {
    //        int byte = 0 + rand()%(255+1)
    //    }
}

std::unique_ptr<std::vector<ip_address>> getIpByMask(std::vector<ip_address> &ips,
                                                     std::vector<int> mask)
{
    std::vector<ip_address> resultVector;

    for (std::vector<ip_address>::iterator it = ips.begin(); it != ips.end();)
    {
        bool matchFLag = true;

        for (size_t i = 0; i < mask.size(); i++)
        {
            if (mask[i] != -1 && mask[i] != it->octets[i])
            {
                matchFLag = false;
            }
        }
        if (matchFLag)
        {
            resultVector.emplace_back(*it);
        }
        ++it;
    }

    return std::move(std::make_unique<std::vector<ip_address>>(resultVector));
}

std::unique_ptr<std::vector<ip_address>> getIpByByte(std::vector<ip_address> &ips, uint8_t byte)
{
    std::vector<ip_address> resultVector;

    std::for_each(ips.begin(), ips.end(), [&](ip_address currentIp) {
        for (size_t i = 0; i < sizeof(currentIp.octets) / sizeof(currentIp.octets[0]); i++)
        {
            if (byte == currentIp.octets[i])
            {
                resultVector.emplace_back(currentIp);
                return;
            }
        }
    });

    return std::move(std::make_unique<std::vector<ip_address>>(resultVector));
}
