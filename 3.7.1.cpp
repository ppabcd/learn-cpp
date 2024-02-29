#include <string>
#include <iostream>
using namespace std;
struct Entry
{
    string name;
    int number;
};

Entry phone_book[1000];

void print_entry(int i)
{
    cout << phone_book[i].name << " " << phone_book[i].number << "\n";
}

int main(int argc, char const *argv[])
{

    return 0;
}
