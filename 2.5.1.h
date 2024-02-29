#include "stack2.h"

namespace Stack
{
    const int max_size = 200;
    struct Rep
    {
        char v[max_size];
        int top;
    };
    const int max = 16;

    Rep stacks[max];
    bool used[max];

    typedef Rep &stack;
}

void Stack::push(stack s, char c)
{ /** check's for overflow and push c*/
}
char Stack::pop(stack s)
{ /** check for underflow and pop*/
}
Stack::stack Stack::create()
{
    // pick unused Rep, mark it use, initialize it , and return a referene to it
}
void Stack::destroy(stack s)
{ /* mark as unused*/
}

struct Bad_pop
{
};
void f()
{
    Stack::stack s1 = Stack::create();
    Stack::stack s2 = Stack::create();

    Stack::push(s1, 'c');
    Stack::push(s2, 'k');

    if (Stack::pop(s1) != 'c')
        throw Bad_pop();
    if (Stack::pop(s2) != 'k')
        throw Bad_pop();

    Stack::destroy(s1);
    Stack::destroy(s2);
}
