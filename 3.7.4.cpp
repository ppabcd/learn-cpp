#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, int> phone_book;

void print_entry(const string &s)
{
    if (int i = phone_book[s])
    {
        cout << s << ' ' << i << '\n';
    }
    else
    {
        cout << "Entry for " << s << " not found.\n";
    }
}

int main(int argc, char const *argv[])
{
    // Adding entries to the phone book
    phone_book["Alice"] = 123456789;
    phone_book["Bob"] = 987654321;
    phone_book["Charlie"] = 111223344;

    // Print an existing entry
    print_entry("Alice");

    // Attempt to print a non-existing entry
    print_entry("Dan");

    return 0;
}
