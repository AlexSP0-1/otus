#include "commands.h"

BaseCommand::BaseCommand(ICommandModel *model)
    : m_model(model)
{}

BaseCommand::~BaseCommand() {}

void BaseCommand::doCommand(std::string command) {}

void BaseCommand::doCommand() {}

BeginBlockCommand::BeginBlockCommand(ICommandModel *model)
    : BaseCommand(model)
{}

void BeginBlockCommand::doCommand()
{
    if (m_model->isStaticMode() && !m_model->isEmpty())
    {
        m_model->doNotify();
        m_model->clearKeeper();
    }
    m_model->nextLevel();
}

EndBlockCommand::EndBlockCommand(ICommandModel *model)
    : BaseCommand(model)
{}

void EndBlockCommand::doCommand()
{
    m_model->checkLevel();
    m_model->previousLevel();
    m_model->doOut();
}

EofCommand::EofCommand(ICommandModel *model)
    : BaseCommand(model)
{}

void EofCommand::doCommand()
{
    m_model->doOut();
}

StoreDataCommand::StoreDataCommand(ICommandModel *model)
    : BaseCommand(model)
{}

void StoreDataCommand::doCommand(std::string text)
{
    if (m_model->isEmpty())
        m_model->setTime();

    m_model->addCommand(std::make_shared<std::string>(text));

    if (m_model->isFull())
        m_model->doOut();
}
