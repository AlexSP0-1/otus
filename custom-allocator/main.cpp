#include "customallocator.h"
#include "customlinkedlist.h"
#include "simplestrategy.h"

#include <map>

static const int SIZE = 10;

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
using allocatorSimple = CustomAllocator<T, SIZE, SimpleStrategy>;

int main(int, char **)
{
    //std::map with std::allocator
    std::map<int, int> mFactorial;
    for (int i = 0; i < SIZE; i++)
    {
        mFactorial.try_emplace(i, MyFactorial(i));
    }

    printMap(mFactorial);

    //using custom allocator
    std::map<int, int, std::less<int>, allocatorSimple<int>> mCustomFactorial;

    for (int i = 0; i < SIZE; i++)
    {
        mCustomFactorial.try_emplace(i, MyFactorial(i));
    }

    printMap(mFactorial);

    //using custom linked list with standart allocator
    CustomLinkedList<int, std::allocator<int>> customList;

    for (int i = 0; i < SIZE; i++)
    {
        customList.add(i);
    }

    for (auto listElement : customList)
    {
        std::cout << listElement << std::endl;
    }

    //using custom linked list with custom allocator
    CustomLinkedList<int, allocatorSimple<int>> customListWithCustomAlloc;

    for (int i = 0; i < SIZE; i++)
    {
        customListWithCustomAlloc.add(i);
    }

    for (auto listElement : customListWithCustomAlloc)
    {
        std::cout << listElement << std::endl;
    }
}
