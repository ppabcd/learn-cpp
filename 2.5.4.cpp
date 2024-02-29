#include <iostream>
#include <list>
using namespace std;

class Stack
{
public:
    class Underflow
    {
    };
    class Overflow
    {
    };
    class Bad_pop
    {
    };

    virtual void push(char c) = 0;
    virtual char pop() = 0;
};

class Array_stack : public Stack
{
    char *p;
    int max_size;
    int top;

public:
    Array_stack(int s) : max_size(s), top(-1)
    {
        p = new char[max_size];
    };
    ~Array_stack()
    {
        delete[] p;
    };

    void push(char c)
    {
        if (top >= max_size - 1)
            throw Overflow();
        p[++top] = c;
    };
    char pop()
    {
        if (top < 0)
            throw Underflow();
        return p[top--];
    };
};

class List_stack : public Stack
{
    list<char> lc;

public:
    List_stack() {}

    void push(char c) { lc.push_front(c); }
    char pop();
};
char List_stack::pop()
{
    char x = lc.front();
    lc.pop_front();
    return x;
}

void f(Stack &s_ref)
{
    s_ref.push('c');
    try
    {
        if (s_ref.pop() != 'c')
            throw Stack::Bad_pop();
    }
    catch (const Stack::Bad_pop &)
    {
        cout << "Bad Pop" << endl;
    }
}

void g()
{
    Array_stack as(200);
    try
    {
        f(as);
    }
    catch (const Stack::Overflow &)
    {
        cout << "Stack Overflow" << endl;
    }
    catch (const Stack::Underflow &)
    {
        cout << "Stack Underflow" << endl;
    }
}

void h()
{

    List_stack ls;
    try
    {
        f(ls);
    }
    catch (const Stack::Underflow &)
    {
        cout << "Stack Underflow" << endl;
    }
}

int main()
{
    g();
    h();
    return 1;
}
