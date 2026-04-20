#include<iostream>
using namespace std;

// TC: O(N)   SC: O(1)
int xorinGivenRange(int N) {
    int ans = 0;
    for (int i=1; i<=N; i++) {
        ans = ans ^ i;
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Xor from 1 to " << n << " is: " << xorinGivenRange(n);
    return 0;
}