#include <iostream>
using namespace std;

void f()
{
    cout << 10;
}
void g()
{
    int i = 10;
    cout << i;
}
void h(int i)
{
    cout << "the value of i is ";
    cout << i;
    cout << "\n";
}
void h2(int i)
{
    cout << "the value of i is " << i << "\n";
}
void k()
{
    cout << 'a';
    cout << 'b';
    cout << 'c';
}
int main()
{
    f();
    g();
    h(10);
    h2(10);
    k();
}
