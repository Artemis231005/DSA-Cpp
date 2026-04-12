#include<iostream>
#include<algorithm>
using namespace std;

string decimalToBinary(int no) {
    if (no == 0) {
        return "0";
    }

    string res = "";
    while (no > 0) {
        if (no % 2 == 1) {
            res += '1';
        } else {
            res += '0';
        }
        no = no / 2;
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