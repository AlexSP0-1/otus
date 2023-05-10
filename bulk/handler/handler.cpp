#include "handler.h"

Handler::Handler(std::unique_ptr<CommandsFactory> factory, std::istream &input)
    : m_cmdFactory(std::move(factory))
    , m_input(input)
{}

void Handler::loop()
{
    while (!m_eof)
    {
        readCommand();
    }
}

void Handler::readCommand()
{
    std::string data = *std::istream_iterator<std::string>(m_input);
    m_eof            = m_input.eof();

    if (m_eof)
    {
        m_cmdFactory->run(COMMAND::EF);
    }
    else if ("{" == data)
    {
        m_cmdFactory->run(COMMAND::BEGIN);
    }
    else if ("}" == data)
    {
        m_cmdFactory->run(COMMAND::END);
    }
    else
    {
        m_cmdFactory->run(COMMAND::ADD, data);
    }
}

bool Handler::isEof()
{
    return false;
}
