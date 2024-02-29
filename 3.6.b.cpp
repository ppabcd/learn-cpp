#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;

    cout << "Please enter your name\n";
    cin >> str;
    // getline(cin, str); // For read the whole line
    cout << "Hello, " << str << "!\n";
    return 0;
}
