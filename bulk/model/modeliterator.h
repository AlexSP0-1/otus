#ifndef MODELITERATOR_H
#define MODELITERATOR_H

#include <iterator>
#include <memory>
#include <vector>

class iterator : public std::iterator<std::forward_iterator_tag, std::string>
{
    using ModelConstIterator = std::vector<std::shared_ptr<std::string>>::const_iterator;

public:
    iterator(ModelConstIterator it)
        : iter(it)
    {}

    iterator operator++()
    {
        iter++;

        return *this;
    }

    bool operator!=(const iterator &other) { return iter != other.iter; }

    const auto operator*() const { return **iter; }

private:
    ModelConstIterator iter;
};

#endif // MODELITERATOR_H
