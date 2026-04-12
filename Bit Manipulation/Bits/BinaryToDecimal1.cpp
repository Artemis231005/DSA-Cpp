#include<iostream>
using namespace std;

// TC: O(n)   SC: O(1)
int binaryToDecimal(string no) {
    int res = 0;

    for (int i = 0; i < no.length(); i++) {
        res = (res << 1) | (no[i] - '0');  // left shift + add current bit
    }

    return res;
}

int main() {
    string no;
    cout << "Enter a binary number: ";
    cin >> no;

    cout << "The equivalent decimal number is: " << binaryToDecimal(no);
    return 0;
}