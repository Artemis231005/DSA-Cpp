#include<iostream>
using namespace std;

int xorinGivenRange(int N) {
    if (N % 4 == 0) {
        return N;
    }
    if (N % 4 == 1) {
        return 1;
    }
    if (N % 4 == 2) {
        return N + 1;
    }
    if (N % 4 == 3) {
        return 0;
    }
    return -1;
}

// TC: O(1)   SC: O(1)
int xorFromLtoR(int l, int r) {
    return xorinGivenRange(l - 1) ^ xorinGivenRange(r);
}

int main(){
    int l, r;
    cout << "Enter starting range: ";
    cin >> l;
    cout << "Enter ending range: ";
    cin >> r;
    
    cout << "Xor from " << l << " to " << r << " is: " << xorFromLtoR(l, r);
    return 0;
}