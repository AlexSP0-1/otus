#include "ip_filter_lib.h"
#include <benchmark/benchmark.h>
#include <iostream>
#include <random>

void generateRandomIpVector(std::vector<std::vector<std::string>> &ips, int size)
{
    ips.clear();
    ips.reserve(size);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist255(0, 255);

    for (size_t i = 0; i < size; i++)
    {
        std::vector<std::string> currentIp;
        for (size_t j = 0; j < 4; j++)
        {
            std::string currentIpStr;

            int8_t byte             = dist255(rng);
            std::string currentByte = std::to_string(byte);

            currentIpStr.append(currentByte);
            if (j != 3)
            {
                currentIpStr.append(".");
            }
            currentIp.emplace_back(currentIpStr);
        }
        ips.emplace_back(currentIp);
    }
}

static void BM_getByMask(benchmark::State &state)
{
    std::vector<std::vector<std::string>> ips;

    generateRandomIpVector(ips, 100);
    std::vector<int> mask = {128, -1, -1, -1};

    for (auto _ : state)
        auto result = getIpsByMask(ips, mask);
}
BENCHMARK(BM_getByMask);

static void BM_getByByte(benchmark::State &state)
{
    std::vector<std::vector<std::string>> ips;

    generateRandomIpVector(ips, 100);

    for (auto _ : state)
        auto result = getIpsByAnyByte(ips, 128);
}
BENCHMARK(BM_getByByte);

static void BM_sortIp(benchmark::State &state)
{
    std::vector<std::vector<std::string>> ips;

    generateRandomIpVector(ips, 100);

    for (auto _ : state)
        lexicalSort(ips);
}
BENCHMARK(BM_sortIp);

BENCHMARK_MAIN();
