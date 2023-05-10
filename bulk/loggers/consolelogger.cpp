#include "consolelogger.h"

#include <experimental/iterator>

void ConsoleLogger::process(const IModelIterator &model)
{
    std::cout << "bulk: ";
    std::copy(model.cbegin(), model.cend(), std::experimental::make_ostream_joiner(std::cout, ", "));
    std::cout << std::endl;
}
