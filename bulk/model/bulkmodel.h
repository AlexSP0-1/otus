#ifndef BULKMODEL_H
#define BULKMODEL_H

#include "icommandmodel.h"
#include "imodeliterator.h"
#include "modeliterator.h"
#include "observable.h"

#include <memory>
#include <string>
#include <vector>

class BulkModel : public IModelIterator, public ICommandModel, public Observable
{
public:
    BulkModel(const size_t &size);

    ~BulkModel() = default;

    friend iterator;

    void doOut() override;

    void addCommand(std::shared_ptr<std::string> inCommand) override;

    void nextLevel() override;

    void previousLevel() override;

    bool isStaticMode() override;

    bool isFull() override;

    bool isEmpty() override;

    void checkLevel() override;

    void setTime() override;

    void doNotify() override;

    void clearKeeper() override;

    iterator cbegin() const override;

    iterator cend() const override;

    std::string getTime() const override;

private:
    size_t m_max_NumberOfCommands;

    size_t m_nestingLevel;

    std::string m_firstCommandTime;

    std::vector<std::shared_ptr<std::string>> m_keeperCommands;
};

#endif
