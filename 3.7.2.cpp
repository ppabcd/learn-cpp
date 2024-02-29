#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Vec : public vector<T>
{
public:
    Vec() : vector<T>() {}
    Vec(int s) : vector<T>(s) {}

    T &operator[](int i) { return this->at(i); }             // Range checked
    const T &operator[](int i) const { return this->at(i); } // range checked
};

/**
 * The code will return out_of_range if there is more than the size
 */
struct Entry
{
    string name;
    int number;
};

Vec<Entry> phone_book(1000); // vector of 1000 elements

void print_entry(int i)
{
    cout << phone_book[i].name << ' ' << phone_book[i].number << '\n';
}

void f()
{
    try
    {
        for (int i = 0; i < 10000; i++)
            print_entry(i);
    }
    catch (out_of_range)
    {
        cout << "range error\n";
    }
}

int main(int argc, char const *argv[])
{
    f();
    return 0;
}
