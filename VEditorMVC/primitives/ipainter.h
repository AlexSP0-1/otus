#ifndef IPAINTER_H
#define IPAINTER_H

#include <string>

class Point;

/*! \brief This is painter common interface for drawing primitives
 *
 */

class IPainter
{
public:
    IPainter() = default;

    virtual ~IPainter() = default;

    /*! \brief Draw delimiter
     *
     */
    virtual void drawDelimiter(const std::string &text) = 0;

    /*! \brief Draw text
     *
     */
    virtual void drawText(const std::string &text) = 0;

    /*! \brief Draw paint
     *
     */
    virtual void drawPoint(const Point &point) = 0;

    /*! \brief Draw line
     *
     */
    virtual void drawLine(const Point &begin, const Point &end) = 0;

    /*! \brief Draw circle
     *
     */
    virtual void drawCircle(const Point &center, const int radius) = 0;
};

#endif
