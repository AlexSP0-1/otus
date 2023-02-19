#ifndef CUSTOMALLOCATOR_H
#define CUSTOMALLOCATOR_H

#include <iostream>

template<typename T, std::size_t BLOCKS, template<typename, std::size_t> class Strategy>
class CustomAllocator : protected Strategy<T, BLOCKS>
{

public:
    using value_type = T;

    template<typename U>
    struct rebind
    {
        using other = CustomAllocator<U, BLOCKS, Strategy>;
    };

    CustomAllocator() = default;

    ~CustomAllocator() = default;

    CustomAllocator(const CustomAllocator &) = delete;

    T *allocate(size_t n) { return Strategy<T, BLOCKS>::allocate(n); }

    void deallocate(T *p, std::size_t n) { Strategy<T, BLOCKS>::deallocate(p, n);    }

    template<typename U, typename... Args>
    void construct(U *p, Args &&...args) const
    {
        new (p) U(std::forward<Args>(args)...);
    }

    template<typename U>
    void destroy(U *p) const
    {
        p->~U();
    }
};

template<typename T, std::size_t BLOCKS, template<typename, std::size_t> class Strategy>
inline bool operator==(const CustomAllocator<T, BLOCKS, Strategy> &,
                       const CustomAllocator<T, BLOCKS, Strategy> &)
{
    return true;
}

template<typename T, std::size_t BLOCKS, template<typename, std::size_t> class Strategy>
inline bool operator!=(const CustomAllocator<T, BLOCKS, Strategy> &,
                       const CustomAllocator<T, BLOCKS, Strategy> &)
{
    return false;
}

#endif //CUSTOMALLOCATOR_H
