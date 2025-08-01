#include<iostream>
using namespace std;

int sumofN (int n) {
    if (n < 1) {
        return 0;
    }
    return n + sumofN(n-1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int sum = sumofN(n);
    cout << "Sum is: " << sum;
    return 0;
}