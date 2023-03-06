#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "primitives/basetypes.h"

/*! \brief This is painter common interface for controllers
 *
 */

class IController
{
public:
    IController()          = default;
    virtual ~IController() = default;

    /*! \brief Clearing current model
     *
     */
    virtual void commandClear() = 0;

    /*! \brief adds new point to model
     *
     */
    virtual void commandNewPoint(const Point &point) = 0;

    /*! \brief adds new line to model
     *
     */
    virtual void commandNewLine(const Point &begin, const Point &end) = 0;

    /*! \brief adds new circle to model
     *
     */
    virtual void commandNewCircle(const Point &center, const int radius) = 0;

    /*! \brief removes last shape from model
     *
     */
    virtual void commandRemoveShape() = 0;

    /*! \brief Load model from file
     *
     */
    virtual void commandLoad(const std::string &filename) = 0;

    /*! \brief Saves model to a file
     *
     */
    virtual void commandSave(const std::string &filename) = 0;

    /*! \brief starts processing user commands
     *
     */
    virtual void loop() = 0;

    /*! \brief read user command to process with current model
     *
     */
    virtual bool readCommand() = 0;
};

#endif
