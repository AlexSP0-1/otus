#include <iostream>

#include "painter.h"

void Painter::drawDelimiter(const std::string &text)
{
    auto length = (int) text.length() < screenWidth ? (screenWidth - (int) text.length()) / 2 : 0;

    std::string filler(length, '-');

    std::cout << filler << text << filler << std::endl;
}

void Painter::drawText(const std::string &text)
{
    std::cout << text << std::endl;
}

void Painter::drawPoint(const Point &point)
{
    std::cout << "primitive POINT at: x - " << point.xCoord << ", y - " << point.yCoord
              << std::endl;
}

void Painter::drawLine(const Point &begin, const Point &end)
{
    std::cout << "primitive LINE at: x - " << begin.xCoord << ", y - " << begin.yCoord << " to x - "
              << end.xCoord << ", y - " << end.yCoord << std::endl;
}

void Painter::drawCircle(const Point &center, const int radius)
{
    std::cout << "primitive CIRCLE at: x - " << center.xCoord << ", y - " << center.yCoord
              << " with radius: " << radius << std::endl;
}
