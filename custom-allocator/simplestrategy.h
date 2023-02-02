template<class T, std::size_t SZ>
class simple_strategy
{
public:
    simple_strategy() noexcept;

    simple_strategy(const simple_strategy &) = delete;

    ~simple_strategy();

    T *allocate(std::size_t);

    void deallocate(T *, std::size_t);

private:
    T *memoryChunk;

    std::size_t usedInChunk;
};

template<typename T, std::size_t SZ>
inline simple_strategy<T, SZ>::simple_strategy() noexcept
    : memoryChunk(nullptr)
    , usedInChunk(0)
{}

template<typename T, std::size_t SZ>
inline simple_strategy<T, SZ>::~simple_strategy()
{
    ::operator delete(memoryChunk);
}

template<typename T, std::size_t SZ>
inline T *simple_strategy<T, SZ>::allocate(std::size_t n)
{
    if (n == 0)
    {
        return nullptr;
    }

    if (!memoryChunk)
    {
        memoryChunk = static_cast<T *>(::operator new(SZ * sizeof(T)));

        if (!memoryChunk)
        {
            throw std::bad_alloc();
        }
    }

    T *res_ptr = memoryChunk + usedInChunk;

    usedInChunk += n;

    if (usedInChunk > SZ)
    {
        throw std::bad_alloc();
    }
    else
    {
        return res_ptr;
    }
}

template<typename T, std::size_t SZ>
inline void simple_strategy<T, SZ>::deallocate(T *, std::size_t)
{}
