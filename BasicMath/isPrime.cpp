#include<iostream>
using namespace std;

void isPrime(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count ++;
        }
    }
    if (count == 2) {
        cout << "Is a Prime Number";
    } else {
        cout << "Not a Prime Number";
    }
}
// TC: O(n)

int main() {
    int n = 4;
    isPrime(n);
    return 0;
}