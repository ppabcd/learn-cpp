#include <stdio.h>
#include <string>
using namespace std;

void f()
{
    string name = "Hello";
    printf("name: %s\n", name.c_str());
}
int main(int argc, char const *argv[])
{
    f();
    return 0;
}
