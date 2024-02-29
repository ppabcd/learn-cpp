#include <string>
#include <list>
#include <iostream>
using namespace std;

struct Entry
{
    string name;
    int number;
};

list<Entry> phone_book;

void print_entry(const string &s)
{
    typedef list<Entry>::const_iterator L1;
    for (L1 i = phone_book.begin(); i != phone_book.end(); ++i)
    {
        const Entry &e = *i; // reference used as shorthand
        if (s == e.name)
        {
            cout << e.name << ' ' << e.number << '\n';
            return;
        }
    }
}

void f(const Entry &e, list<Entry>::iterator i, list<Entry>::iterator p)
{
    phone_book.push_front(e); // Add at begining
    phone_book.push_back(e);  // Add at back
    phone_book.insert(i, e);  // Add before the element reffered to by 'i'

    phone_book.erase(p); // remove the element reffered to by 'p'
}

int main()
{
    // Add some entries to the phone book
    phone_book.push_back({"John Doe", 123456});
    phone_book.push_back({"Jane Smith", 987654});
    phone_book.push_back({"Alice Brown", 456789});

    // Print an entry
    print_entry("Jane Smith");

    // Manipulate entries
    // Note: This is just a demonstration and may not be meaningful
    // as it depends on having valid iterators 'i' and 'p'.
    // For simplicity, let's assume we want to add a new entry and remove the first one.
    auto i = phone_book.begin();
    advance(i, 2); // Move iterator to the third position
    Entry new_entry = {"Bob White", 111222};
    f(new_entry, i, phone_book.begin()); // This will also remove the first entry ("John Doe")

    // Print all entries to show the result
    for (const auto &e : phone_book)
    {
        cout << e.name << ' ' << e.number << '\n';
    }

    return 0;
}
