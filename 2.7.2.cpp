#include <complex>
#include <vector>
#include <list>
#include <iostream>

template <class In, class Out>
void copys(In from, In too_far, Out to)
{
    while (from != too_far)
    {
        *to = *from; // Copy element pointed to
        ++to;        // next output
        ++from;      // next input
    }
}

char vc1[200]; // Array of 200 characters
char vc2[500]; // Array of 500 characters

void f()
{
    /**
     * Additional code for filling the variable
     */
    std::fill(&vc1[0], &vc1[200], 'A'); // Fill vc1 with 'A's
    /**
     * End fill
     */
    copys(&vc1[0], &vc1[200], &vc2[0]);
}

std::complex<double> ac[200];
void g(std::vector<std::complex<double>> &vc, std::list<std::complex<double>> &lc)
{
    lc.resize(200); // Prevent error
    copys(&ac[0], &ac[200], lc.begin());

    vc.resize(lc.size()); // Prevent error
    copys(lc.begin(), lc.end(), vc.begin());
}

int main()
{
    // Prepare and demonstrate array copying
    f();

    // Prepare complex array with sample values
    std::fill_n(ac, 200, std::complex<double>(1.0, 2.0)); // Fill ac with complex numbers

    std::vector<std::complex<double>> vc;
    std::list<std::complex<double>> lc;
    g(vc, lc); // Demonstrate copying between complex array, list, and vector

    // Optionally, print some elements from vc2 and vc to verify
    std::cout << "vc2[0]: " << vc2[0] << "\n";
    std::cout << "First element in vc: " << vc.front() << std::endl;

    return 0;
}
