#include "customallocator.h"
#include "customlinkedlist.h"
#include "simplestrategy.h"

#include <map>

static const int SZ = 10;

int MyFactorial(int n)
{
    int current = 1;

    for (int i = 2; i <= n; i++)
    {
        current *= n;
    }

    return current;
}

void printMap(std::map<int, int> &m)
{
    for (const auto &[key, value] : m)
    {
        std::cout << key << " " << value << std::endl;
    }
}

template<typename T>
using allocatorSimple = Custom_allocator<T, SZ, simple_strategy>;

int main(int, char **)
{
    //std::map with std::allocator
    std::map<int, int> mFactorial;
    for (int i = 0; i < SZ; i++)
    {
        mFactorial.try_emplace(i, MyFactorial(i));
    }

    printMap(mFactorial);

    //using custom allocator
    std::map<int, int, std::less<int>, Custom_allocator<int, SZ, simple_strategy>> mCustomFactorial;

    for (int i = 0; i < SZ; i++)
    {
        mCustomFactorial.try_emplace(i, MyFactorial(i));
    }

    printMap(mFactorial);

    //using custom linked list with standart allocator
    CustomLinkedList<int, std::allocator<int>> customList;

    for (int i = 0; i < SZ; i++)
    {
        customList.add(i);
    }

    for (auto it = customList.begin(); it != customList.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    //using custom linked list with custom allocator
    CustomLinkedList<int, allocatorSimple<int>> customListWithCustomAlloc;

    for (int i = 0; i < SZ; i++)
    {
        customListWithCustomAlloc.add(i);
    }

    for (auto it = customListWithCustomAlloc.begin(); it != customListWithCustomAlloc.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}
