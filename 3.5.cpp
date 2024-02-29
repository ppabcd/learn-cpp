#include <string>
#include <iostream>
using namespace std;

string s1 = "Hello";
string s2 = "World";

void m1()
{
    string s3 = s1 + ", " + s2 + "!\n";
    cout << s3;
}

void m2(string &s1, string &s2)
{
    s1 = s1 + "\n";
    s2 += '\n';
    cout << s1 << s2;
}

string name = "Niels Stroustrup";
void m3()
{
    string s = name.substr(6, 10);
    name.replace(0, 5, "Nicholas");
    cout << s;
}

int main()
{
    m1();
    string s1 = "Hello";
    string s2 = "World";
    m2(s1, s2);
    m3();

    return 0;
}
