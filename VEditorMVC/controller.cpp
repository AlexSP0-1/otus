#include <iostream>

#include "controller.h"

Controller::Controller(IModel *model, IObserver *view)
    : m_model(model)
    , m_view(view)
{}

void Controller::commandClear()
{
    m_model->newModel();
    m_model->notify();
}

void Controller::commandNewPoint(const Point &point)
{
    m_model->addPoint(point);
    m_model->notify();
}

void Controller::commandNewLine(const Point &begin, const Point &end)
{
    m_model->addLine(begin, end);
    m_model->notify();
}

void Controller::commandNewCircle(const Point &center, const int radius)
{
    m_model->addCirlce(center, radius);
    m_model->notify();
}

void Controller::commandRemoveShape()
{
    m_model->removeLast();
    m_model->notify();
}

void Controller::commandLoad(const std::string &filename)
{
    //TO DO implement load
    std::cout << "Loaded file: " << filename << std::endl;
}

void Controller::commandSave(const std::string &filename)
{
    //TO DO implement save
    std::cout << "Saved file: " << filename << std::endl;
}

void Controller::loop()
{
    while (readCommand())
        ;
}

bool Controller::readCommand()
{
    std::string currentCommand;
    int x = 0, y = 0, xe = 0, ye = 0;

    std::cin.clear();

    std::cout
        << "input command: (ap: add Point; al: add line; ac: add circle; rm: remove last object;"
        << std::endl;

    std::cout << "clear model; opn: open doc; sav: save doc; exit: exited from this)>" << std::endl;

    std::cin >> currentCommand;

    if (currentCommand == "exit")
    {
        return false;
    }
    else if (currentCommand == "ap")
    {
        std::cout << "input locatoin - x and y: ";

        std::cin >> x >> y;

        //TODO validate

        commandNewPoint(Point{x, y});

        return true;
    }
    else if (currentCommand == "ac")
    {
        std::cout << "input locatoin - x and y and radius: ";

        std::cin >> x >> y >> xe;

        //TODO validate

        commandNewCircle(Point{x, y}, xe);

        return true;
    }
    else if (currentCommand == "al")
    {
        std::cout << "input begin locatoin - x and y and end locatoin - x1 and y1: ";

        std::cin >> x >> y >> xe >> ye;

        //TODO validate

        commandNewLine(Point{x, y}, Point{xe, ye});

        return true;
    }
    else if (currentCommand == "rm")
    {
        commandRemoveShape();

        return true;
    }
    else if (currentCommand == "clr")
    {
        commandClear();

        return true;
    }
    else if (currentCommand == "opn")
    {
        commandLoad("exampleModel");

        return true;
    }
    else if (currentCommand == "sav")
    {
        commandSave("newModel");

        return true;
    }
    else
    {
        std::cout << "bad command, try again" << std::endl;

        return true;
    }
}
