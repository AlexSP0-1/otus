#ifndef IMODEL_H
#define IMODEL_H

#include <string>

#include "observable.h"
#include "primitives/basetypes.h"
#include "primitives/ipainter.h"

/*! \brief This is painter common interface for models
 *
 */

class IModel : public Observable
{
public:
    IModel()          = default;
    virtual ~IModel() = default;

    virtual void newModel() = 0;

    virtual void openModel(std::string &) = 0;

    virtual void saveModel(std::string &) = 0;

    virtual void addPoint(const Point &) = 0;

    virtual void addLine(const Point &, const Point &) = 0;

    virtual void addCirlce(const Point &, const int) = 0;

    virtual void removeLast() = 0;

    virtual void draw(IPainter *) = 0;
};

#endif
