#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include <memory>
#include <stdlib.h>
#include <iostream>
#include <arpa/inet.h>

struct ip_address {
    union{
        uint32_t ip;
        uint8_t a,b,c,d;
    };
};



std::string splitLine(const std::string &str, char d);

void printIpVector(std::vector<std::string> &ipVector);

void printIpVector(std::vector<ip_address> &printIpVector);

