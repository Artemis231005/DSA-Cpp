#include<iostream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    cout << "No of digits: " << countDigits(7389);
}

// TC: O(log10(N))