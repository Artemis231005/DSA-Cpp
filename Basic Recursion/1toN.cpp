#include<iostream>
using namespace std;

void Ntimes (int i, int n) {
    if (i > n) {
        return;
    }
        cout << i << endl;
        Ntimes(i + 1, n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int i = 1;
    Ntimes(i, n);
    return 0;
}