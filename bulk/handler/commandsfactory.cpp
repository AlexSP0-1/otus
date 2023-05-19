#include "commandsfactory.h"

void CommandsFactory::addCommand(COMMAND cmd, std::unique_ptr<ICommand> command)
{
    m_commands.emplace(cmd, std::move(command));
}

void CommandsFactory::run(COMMAND cmd)
{
    m_commands[cmd]->doCommand();
}

void CommandsFactory::run(COMMAND cmd, std::string str)
{
    m_commands[cmd]->doCommand(str);
}
