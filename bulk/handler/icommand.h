#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void doCommand() = 0;

    virtual void doCommand(std::string command) = 0;
};

#endif // ICOMMAND_H
