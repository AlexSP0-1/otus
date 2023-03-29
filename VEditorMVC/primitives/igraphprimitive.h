#ifndef IPRIMITIVE_H
#define IPRIMITIVE_H

#include "basetypes.h"
#include "ipainter.h"

/*! \brief This interface is common for all primitives
 *
 */
class IGraphPrimitiveObject
{
public:
    /*! \brief This interface is common for all primitives
     *
     */
    virtual void draw(IPainter *) const = 0;

    /*! \brief This interface is common for all primitives
     *
     */
    virtual void setEnd(const Point &) = 0;

    /*! \brief This interface is common for all primitives
     *
     */
    virtual void setRadius(const int) = 0;
};

#endif
