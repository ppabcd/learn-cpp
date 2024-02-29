#include <string>
#include <iostream>
#include <vector>
using namespace std;
struct Entry
{
    string name;
    int number;
};

vector<Entry> phone_book(1000); // vector of 1000 elements
// vector<Entry> phone_book[1000]; // 1000 empty vectors
void print_entry(int i)
{
    cout << phone_book[i].name << ' ' << phone_book[i].number << '\n';
}

void add_entries(int n)
{
    phone_book.resize(phone_book.size() + n);
}
void f(vector<Entry> &v)
{
    vector<Entry> v2 = phone_book;
    v = v2;
}
