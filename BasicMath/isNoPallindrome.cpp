#include<iostream>
using namespace std;

int isPallindrome (int n) {
    int lastDigit;
    int reverse = 0;
    while(n > 0) {
        lastDigit = n % 10;
        n /= 10;
        reverse = (reverse * 10) + lastDigit; 
    }
    return reverse;
}

int main() {
    int no = 121;
    int reversed = isPallindrome(no);
    if (no == reversed) {
        cout << "Is a pallindrome";
    } else {
        cout << "Not a pallindrome";
    }
    return 0;
}