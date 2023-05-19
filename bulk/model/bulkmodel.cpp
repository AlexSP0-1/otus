#include <chrono>

#include "bulkmodel.h"

BulkModel::BulkModel(const size_t &size)
    : m_max_NumberOfCommands(size)
    , m_nestingLevel{0}
    , m_firstCommandTime("")
    , m_keeperCommands({})
{}

std::string BulkModel::getTime() const
{
    return m_firstCommandTime;
}

void BulkModel::doOut()
{
    bool st  = isStaticMode();
    bool emp = isEmpty();
    if (isStaticMode() && !isEmpty())
    {
        notify(*this);
        clearKeeper();
    }
}

void BulkModel::addCommand(std::shared_ptr<std::string> inCommand)
{
    m_keeperCommands.push_back(inCommand);
}

void BulkModel::nextLevel()
{
    ++m_nestingLevel;
}

void BulkModel::previousLevel()
{
    --m_nestingLevel;
}

bool BulkModel::isStaticMode()
{
    return !m_nestingLevel;
}

bool BulkModel::isFull()
{
    return m_max_NumberOfCommands == m_keeperCommands.size();
}

bool BulkModel::isEmpty()
{
    return m_keeperCommands.empty();
}

void BulkModel::checkLevel()
{
    if (isStaticMode())
        throw std::out_of_range("Dynamic block parsing isn't correct.");
}

void BulkModel::setTime()
{
    using namespace std::chrono;

    auto timePoint        = time_point_cast<milliseconds>(system_clock::now());
    auto timeMilliSeconds = timePoint.time_since_epoch().count();

    m_firstCommandTime = std::to_string(timeMilliSeconds);
}

void BulkModel::doNotify()
{
    notify(*this);
}

void BulkModel::clearKeeper()
{
    m_keeperCommands.clear();
}

iterator BulkModel::cbegin() const
{
    return iterator(m_keeperCommands.cbegin());
}

iterator BulkModel::cend() const
{
    return iterator(m_keeperCommands.cend());
}
