#include "stack.h"

namespace Stack
{
    const int max_size = 200;
    char v[max_size];
    int top = 0;
}

char Stack::pop()
{
    return 'c';
}
void Stack::push(char c)
{
    if (top == max_size)
        throw Overflow();
    // push c
}

void f()
{
    try
    {
        while (true)
            Stack::push('c');
    }
    catch (Stack::Overflow)
    {
        // oops: stack overflow: take appropriate action
    }
}
