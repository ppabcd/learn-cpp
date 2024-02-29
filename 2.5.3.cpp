#include <iostream>

class Stack
{
    char *v;
    int top;
    int max_size;

public:
    class Underflow // As exception
    {
    };
    class Overflow // As exception
    {
    };
    class Bad_size // As exception
    {
    };

    Stack(int s); // Contructor
    ~Stack();     // Descructor

    void push(char c);
    char pop();
};

Stack::Stack(int s) // constructor
{
    top = 0;
    if (s < 0 || 10000 < s)
        throw Bad_size();
    max_size = s;
    v = new char[s]; // Allocate elements on the free store (heap, dynamic store)
}
Stack::~Stack() // descructor
{
    delete[] v; // free the elements for possible reuse of their space
}
// Additional code
void Stack::push(char c)
{
    if (top == max_size)
        throw Overflow(); // Check for stack overflow
    v[top++] = c;         // Add the character to the stack and increment top
    top = top + 1;
}

char Stack::pop()
{
    if (top <= 0)
        throw Underflow(); // Check for stack underflow
    return v[--top];       // Return the top character and decrement top
}

using namespace std;
// Example usage
int mains()
{
    try
    {
        Stack stack(10);

        stack.push('H');
        stack.push('e');
        stack.push('l');
        stack.push('l');
        stack.push('o');

        // Pop characters off the stack and print them
        cout << "Popped characters: " << endl;
        while (true)
        {
            char c = stack.pop();
            cout << c << endl;
        }
    }
    catch (Stack::Overflow &e)
    {
        cout << "Stack overflow error." << endl;
    }
    catch (Stack::Underflow &e)
    {
        cout << "Stack underflow error." << endl;
    }
    catch (Stack::Bad_size &e)
    {
        cout << "Invalid stack size." << endl;
    }

    return 0;
}
Stack s_var1(10);           // Global stack with 10 elements
void f(Stack &s_ref, int i) // reference to Stack
{
    Stack s_var2(i);              // local stack with i elements
    Stack *s_ptr = new Stack(20); // pointer to Stack allocated on free store

    s_var1.push('a');
    s_var2.push('b');
    s_ref.push('c');
    s_ptr->push('d');
    // Let's simulate popping the character from the dynamically allocated stack to show its use
    try
    {
        char c = s_ptr->pop();
        cout << "Dynamically allocated stack popped character: " << c << endl; // Should print 'd'
    }
    catch (Stack::Underflow &)
    {
        cout << "Underflow occurred in dynamically allocated stack." << endl;
    }

    delete s_ptr; // Clean up the dynamically allocated memory
}

int main()
{
    Stack s_global(10); // Global stack with space for 10 elements
    Stack s_main(5);    // Stack created in main, with space for 5 elements

    // Call f with s_main as the reference stack and 3 as the size for the local stack inside f
    f(s_main, 3);

    // Attempt to pop elements from the global stack
    cout << "Global stack popped character: ";
    try
    {
        char c = s_global.pop();
        cout << c << endl; // Should print 'a' if global stack is used inside f
    }
    catch (Stack::Underflow &)
    {
        cout << "Underflow occurred in global stack." << endl;
    }

    // Attempt to pop elements from the main stack
    cout << "Main stack popped character: ";
    try
    {
        char c = s_main.pop();
        cout << c << endl; // Should print 'c' if s_main is correctly referenced in f
    }
    catch (Stack::Underflow &)
    {
        cout << "Underflow occurred in main stack." << endl;
    }

    // No direct way to access s_var2 from here since it's local to f
    // No need to explicitly delete s_ptr since it's handled inside f (assuming deletion is added)

    return 0;
}
