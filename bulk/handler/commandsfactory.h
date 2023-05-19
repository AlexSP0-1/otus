#ifndef COMMANDSFACTORY_H
#define COMMANDSFACTORY_H

#include "commands.h"
#include <map>
#include <memory>

class CommandsFactory
{
public:
    CommandsFactory() = default;

    void addCommand(COMMAND cmd, std::unique_ptr<ICommand> command);

    void run(COMMAND cmd);

    void run(COMMAND cmd, std::string str);

private:
    std::map<COMMAND, std::unique_ptr<ICommand>> m_commands;
    std::string m_string;
};

#endif // COMMANDSFACTORY_H
