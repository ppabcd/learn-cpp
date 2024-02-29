#include <list>
#include <complex>
#include <iostream>
#include "stack3.h"
using namespace std;

Stack<char> sc(200);
Stack<complex<double>> scplx(30);
Stack<list<int>> sli(45);

void f()
{
    sc.push('c');
    if (sc.pop() != 'c')
        throw Bad_pop();

    scplx.push(complex<double>(1, 2));
    if (scplx.pop() != complex<double>(1, 2))
        throw Bad_pop();
}

int main()
{
    try
    {
        f();
    }
    catch (const Bad_pop &)
    {
        cout << "Bad pop occurred." << endl;
    }

    return 0;
}
