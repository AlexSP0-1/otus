#ifndef IPFACTORY_H
#define IPFACTORY_H

#include "igraphprimitive.h"
#include <memory>

/*! \brief This interface is common for all factories
 *
 */

class IPFactory
{
public:
    IPFactory()          = default;
    virtual ~IPFactory() = default;

public:
    /*! \brief Creates point primitive
     *
     */
    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &) = 0;

    /*! \brief Creates line primitive
     *
     */
    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &, const Point &) = 0;

    /*! \brief Creates circle primitive
     *
     */
    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &, const int) = 0;
};

#endif // IPFACTORY_H
