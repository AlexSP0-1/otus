#include "customallocator.h"
#include "customlinkedlist.h"
#include "simplestrategy.h"

static const int SZ = 15; //chunk size

int MyFactorial(int n)
{
    int current = 1;

    for (int i = 2; i <= n; i++)
    {
        current *= n;
    }

    return current;
}

int main(int, char **) {}
