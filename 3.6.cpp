#include <iostream>
using namespace std;

void f()
{
    int i;
    cin >> i;

    double d;
    cin >> d;

    cout << i << d;
}

int main(int argc, char const *argv[])
{
    // f();

    const float factor = 2.54; // 1 inch equals 2.54
    float x, in, cm;
    char ch = 0;

    cout << "enter length: ";
    cin >> x;  // read a floating point number
    cin >> ch; // read suffix

    switch (ch)
    {
    case 'i':
        in = x;
        cm = x * factor;
        break;
    case 'c':
        in = x / factor;
        cm = x;
        break;
    default:
        in = cm = 0;
        break;
    }
    cout << in << "in = " << cm << " cm\n";
    return 0;
}
