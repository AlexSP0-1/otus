#ifndef BASETYPES_H
#define BASETYPES_H

struct Point
{
    int xCoord = 0;
    int yCoord = 0;
};

enum PrimitiveType
{
    POINT,
    LINE,
    CIRCLE
};

#endif
