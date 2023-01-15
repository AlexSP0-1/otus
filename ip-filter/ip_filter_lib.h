#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include <memory>
#include <stdlib.h>
#include <iostream>

std::vector<std::string> split(const std::string &str, char d);

void lexicalSort(std::vector<std::vector<std::string>> &ips);

void printIpVector(std::vector<std::vector<std::string>> &ipVector);

std::unique_ptr<std::vector<std::vector<std::string>>> getIpsByMask(
    std::vector<std::vector<std::string>> ips, std::vector<int> &mask);

std::unique_ptr<std::vector<std::vector<std::string>>> getIpsByAnyByte(
    std::vector<std::vector<std::string>> ips, int byte);
