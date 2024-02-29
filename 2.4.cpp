#include <iostream>
using namespace std;

namespace Stack
{
    const int max_size = 200;
    char v[max_size];

    void push(char){/* Check the overflow and push */};
    char pop(){/* Check the underflow and pop */};
}
void f()
{
    Stack::push('c');
    if (Stack::pop() != 'c')
        cout << "Impossible";
}
