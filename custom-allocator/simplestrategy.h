#ifndef SIMPLESTRATEGY_H
#define SIMPLESTRATEGY_H

template<class T, std::size_t SIZE>
class SimpleStrategy
{

public:
    SimpleStrategy() noexcept;

    SimpleStrategy(const SimpleStrategy &) = delete;

    ~SimpleStrategy();

    T *allocate(std::size_t);

    void deallocate(T *, std::size_t);

private:
    T *memoryChunk;

    std::size_t usedInChunk;
};

template<typename T, std::size_t SIZE>
inline SimpleStrategy<T, SIZE>::SimpleStrategy() noexcept
    : memoryChunk(nullptr)
    , usedInChunk(0)
{}

template<typename T, std::size_t SIZE>
inline SimpleStrategy<T, SIZE>::~SimpleStrategy()
{
    ::operator delete(memoryChunk);
}

template<typename T, std::size_t SIZE>
inline T *SimpleStrategy<T, SIZE>::allocate(std::size_t n)
{
    if (n == 0)
    {
        return nullptr;
    }

    if (!memoryChunk)
    {
        memoryChunk = static_cast<T *>(::operator new(SIZE * sizeof(T)));

        if (!memoryChunk)
        {
            throw std::bad_alloc();
        }
    }

    T *res_ptr = memoryChunk + usedInChunk;

    usedInChunk += n;

    if (usedInChunk > SIZE)
    {
        throw std::bad_alloc();
    }
    else
    {
        return res_ptr;
    }
}

template<typename T, std::size_t SIZE>
inline void SimpleStrategy<T, SIZE>::deallocate(T *, std::size_t)
{}


#endif //SIMPLESTRATEGY_H
