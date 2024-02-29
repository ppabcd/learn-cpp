#include <iostream>
#include "stack.h"
using namespace std;

namespace Stack
{
    const int max_size = 200;
    char v[max_size];
    int top = 0;
}
void Stack::push(char c)
{
}

char Stack::pop()
{
    return 'c';
}

void f()
{
    Stack::push('c');
    if (Stack::pop() != 'c')
        // error("impossible")
        cout << "Impossible";
}

int main()
{
    f();
    return 1;
}
