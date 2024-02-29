#include <iostream>
using namespace std;

void another_function()
{
    int v1[10];
    int v2[10];

    for (int i = 0; i < 10; i++)
        v1[i] = v2[i];
}

int main()
{
    another_function();
    return 1;
}
