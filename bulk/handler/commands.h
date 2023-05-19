#ifndef COMMANDS_H
#define COMMANDS_H

#include "../model/icommandmodel.h"
#include "icommand.h"
#include <string>

enum COMMAND
{
    BEGIN,
    END,
    EF,
    ADD
};

class BaseCommand : public ICommand
{
public:
    BaseCommand(ICommandModel *model);

    virtual ~BaseCommand();

public:
    void doCommand(std::string command) override;

    void doCommand() override;

protected:
    ICommandModel *m_model;
};

class BeginBlockCommand : public BaseCommand
{
public:
    BeginBlockCommand(ICommandModel *model);
    virtual ~BeginBlockCommand() = default;

    void doCommand() override;
};

class EndBlockCommand : public BaseCommand
{
public:
    EndBlockCommand(ICommandModel *model);
    virtual ~EndBlockCommand() = default;

    void doCommand() override;
};

class EofCommand : public BaseCommand
{
public:
    EofCommand(ICommandModel *model);
    virtual ~EofCommand() = default;

    void doCommand() override;
};

class StoreDataCommand : public BaseCommand
{
public:
    StoreDataCommand(ICommandModel *model);
    virtual ~StoreDataCommand() = default;

    void doCommand(std::string text);
};

#endif
