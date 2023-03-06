#ifndef PAINTER_H
#define PAINTER_H

#include "primitives/basetypes.h"
#include "primitives/ipainter.h"
#include <string>

class Painter : public IPainter
{
public:
    const int screenWidth = 80;

    Painter()          = default;
    virtual ~Painter() = default;

    virtual void drawDelimiter(const std::string &text) override;

    virtual void drawText(const std::string &text) override;

    virtual void drawPoint(const Point &point) override;

    virtual void drawLine(const Point &begin, const Point &end) override;

    virtual void drawCircle(const Point &center, const int radius) override;
};

#endif // PAINTER_H
