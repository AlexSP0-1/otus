#include "ip_filter_lib.h"

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

void lexicalSort(std::vector<std::vector<std::string>> &ips)
{
    std::sort(ips.begin(),
              ips.end(),
              [](const std::vector<std::string> &ip1, const std::vector<std::string> &ip2) {
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
              });
}

void printIpVector(std::vector<std::vector<std::string>> &ipVector)
{
    std::for_each(ipVector.begin(), ipVector.end(), [&](std::vector<std::string> &currentIp) {
        std::for_each(currentIp.begin(), currentIp.end(), [&](std::string currentIpPart) {
            if (currentIpPart != currentIp.at(0))
            {
                std::cout << ".";
            }
            std::cout << currentIpPart;
        });
        std::cout << std::endl;
    });
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

    std::for_each(ips.begin(), ips.end(), [&](std::vector<std::string> currentIp) {
        std::for_each(currentIp.begin(), currentIp.end(), [&](std::string currentIpPart) {
            if (byte == atoi(currentIpPart.c_str()))
            {
                newVector.emplace_back(currentIp);
            }
        });
    });

    return std::move(std::make_unique<std::vector<std::vector<std::string>>>(newVector));
}
