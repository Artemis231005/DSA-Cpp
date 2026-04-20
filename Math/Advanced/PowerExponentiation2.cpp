#include<iostream>
using namespace std;

// TC: O(log2N) (dividing by 2 most times, other time subtracting by 1)   SC: O(1)
double powerExponentiation(double base, int exponent) {
    double ans = 1.0;
    int m = exponent;

    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            ans = ans * base;
            exponent--;
        } else {
            base = base * base;
            exponent = exponent / 2;
        }
    }
    
    return ans;
}

int main(){
    int n, power;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter a power: ";
    cin >> power;
    
    cout << n << "^" << power << " is: " << powerExponentiation(n, power);
    return 0;
}