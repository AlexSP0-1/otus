#include "filelogger.h"

#include <experimental/iterator>
#include <fstream>
#include <iostream>

FileLogger::~FileLogger() {}

void FileLogger::process(const IModelIterator &model)
{
    std::ofstream file("bulk" + model.getTime() + ".log");
    std::copy(model.cbegin(), model.cend(), std::experimental::make_ostream_joiner(file, ", "));
    file << std::endl;
}
