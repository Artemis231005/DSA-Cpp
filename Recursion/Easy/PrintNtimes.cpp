#include<iostream>
using namespace std;

void printNtimes (int n) {
    if (n <= 0) {
        return;
    }
    cout << "Ishi" << endl;
    printNtimes(n-1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printNtimes(n);
    return 0;
}