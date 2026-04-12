#include<iostream>
#include<algorithm>
using namespace std;

string decimalToBinary(int no) {
    if (no == 0) return "0";

    string res = "";

    while (no > 0) {
        if (no & 1)   // check last bit
            res += '1';
        else
            res += '0';

        no = no >> 1; // right shift (means divide by 2)
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int no;
    cout << "Enter a decimal number: ";
    cin >> no;

    cout << "The equivalent binary number is: " << decimalToBinary(no);
    return 0;
}