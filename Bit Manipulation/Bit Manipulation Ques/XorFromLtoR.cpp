#include<iostream>
using namespace std;

// TC: O(N)   SC: O(1)
int xorinGivenRange(int l, int r) {
    int ans = 0;
    for (int i=l; i<=r; i++) {
        ans = ans ^ i;
    }
    return ans;
}

int main(){
    int l, r;
    cout << "Enter starting range: ";
    cin >> l;
    cout << "Enter ending range: ";
    cin >> r;
    
    cout << "Xor from " << l << " to " << r << " is: " << xorinGivenRange(l, r);
    return 0;
}