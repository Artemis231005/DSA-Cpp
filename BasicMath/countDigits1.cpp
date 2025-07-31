#include<iostream>
#include<cmath>             // if error is that log10 is out of scope, add header file that includes it
using namespace std;

int countDigits(int n) {
    int count = (int)log10(n) + 1;
    return count;
}

int main() {
    cout << "No of digits: " << countDigits(10897);
}

// TC: O(log10(N))