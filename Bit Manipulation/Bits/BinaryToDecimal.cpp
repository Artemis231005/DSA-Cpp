#include<iostream>
#include<algorithm>
using namespace std;

// TC: O(length of str)   SC: O(1)
int binaryToDecimal(string no) {
    int res = 0;
    int p2 = 1;
    for (int i=no.length()-1; i>=0; i--) {
        if (no[i] == '1') {
            res += p2;
        }
        p2 *= 2;
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