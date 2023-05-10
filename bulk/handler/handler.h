#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <iterator>
#include <memory>
#include <string>

#include "commandsfactory.h"

class Handler
{
public:
    Handler(std::unique_ptr<CommandsFactory> factory, std::istream &input);

    ~Handler() = default;

public:
    void loop();

    void readCommand();

    bool isEof();

private:
    bool m_eof = false;

    std::unique_ptr<CommandsFactory> m_cmdFactory;

    std::istream &m_input;
};

#endif
