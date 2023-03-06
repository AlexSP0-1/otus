#include "model.h"

void Model::newModel()
{
    graphObjects.clear();
}

void Model::openModel(std::string &)
{
    //open and load file
}

void Model::saveModel(std::string &)
{
    //serialize model and save it to the file
}

void Model::addPoint(const Point &beginPoint)
{
    graphObjects.push_back(
        factoryObjects.primitiveObjects[PrimitiveType::POINT]->create(beginPoint));
}

void Model::addLine(const Point &beginPoint, const Point &endPoint)
{
    graphObjects.push_back(
        factoryObjects.primitiveObjects[PrimitiveType::LINE]->create(beginPoint, endPoint));
}

void Model::addCirlce(const Point &beginPoint, const int radius)
{
    graphObjects.push_back(
        factoryObjects.primitiveObjects[PrimitiveType::CIRCLE]->create(beginPoint, radius));
}

void Model::removeLast()
{
    if (!graphObjects.empty())
    {
        graphObjects.pop_back();
    }
}

void Model::draw(IPainter *painter)
{
    painter->drawDelimiter("top_of_the_screen");

    if (graphObjects.empty())
    {
        painter->drawText("nothing to draw");
    }
    else
    {
        for (auto &object : graphObjects)
        {
            object->draw(painter);
        }
    }

    painter->drawDelimiter("bottom_of_the_screen");
}
