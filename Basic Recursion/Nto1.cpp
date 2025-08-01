#include<iostream>
using namespace std;

void Ntimes (int n) {
    if (n < 1) {
        return;
    }
    cout << n << endl;
    Ntimes(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Ntimes(n);
    return 0;
}