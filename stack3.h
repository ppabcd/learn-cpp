class Bad_pop
{
};

template <class T>
class Stack
{
    T *v;
    int max_size;
    int top;

public:
    class Underflow
    {
    };
    class Overflow
    {
    };

    Stack(int s);
    ~Stack();

    void push(T);
    T pop();
};

template <class T>
void Stack<T>::push(T c)
{
    if (top == max_size)
        throw Overflow();
    v[top] = c;
    top = top + 1;
}
template <class T>
T Stack<T>::pop()
{
    if (top == 0)
        throw Underflow();
    top = top - 1;
    return v[top];
}
template <class T>
Stack<T>::Stack(int s) : max_size(s), top(0)
{
    v = new T[max_size];
}

template <class T>
Stack<T>::~Stack()
{
    delete[] v;
}
