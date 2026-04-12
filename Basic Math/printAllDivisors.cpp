#include<iostream>
using namespace std;

void printDivisors (int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    int n = 36;
    cout << "Divisors of " << n << " are: ";
    printDivisors(n);
}

// TC: O(n)