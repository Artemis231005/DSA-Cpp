#include<iostream>
#include<cmath>
#include <vector>
#include <algorithm>
using namespace std;

void printDivisors (int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }
    // TC of inserting divisors:  O(√n)

    sort(divisors.begin(), divisors.end());
    // TC of sorting divisors: O(√n * log(√n))

    for (int i : divisors) {
        cout << i << " ";
    }
    // TC of printing divisors:  O(√n)
}

int main() {
    int n = 36;
    cout << "Divisors of " << n << " are: ";
    printDivisors(n);
}
// Final Time Complexity: O(√n * log(√n))