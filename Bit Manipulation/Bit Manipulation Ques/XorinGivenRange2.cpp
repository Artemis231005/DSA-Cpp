#include<iostream>
using namespace std;

// TC: O(1)   SC: O(1)
int xorinGivenRange(int N) {
    if (N % 4 == 1) {
        return 1;
    }
    if (N % 4 == 2) {
        return N + 1;
    }
    if (N % 4 == 3) {
        return 0;
    }
    if (N % 4 == 0) {
        return N;
    }
    return -2;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Xor from 1 to " << n << " is: " << xorinGivenRange(n);
    return 0;
}