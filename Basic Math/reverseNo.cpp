#include<iostream>
using namespace std;

int reverseNo (int n) {
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
    int no = 7389;
    cout << "Reverse of " << no << " : " << reverseNo(no); 
}