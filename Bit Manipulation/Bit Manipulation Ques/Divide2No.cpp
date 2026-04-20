#include<iostream>
#include<climits>
using namespace std;

// TC: O(log2N)^2   SC: O(1)
// Use long to prevent errors from abs and left shifting
int divide2Integers(int dividend, int divisor) {
    if (dividend == divisor) {
        return 1;
    }
    if (divisor == 0) {
        return -1;
    }
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    bool sign = true;                       // true means it is a +ve
    if (dividend >= 0 && divisor < 0) {
        sign = false;                       // means -ve
    }
    if (dividend < 0 && divisor > 0) {
        sign = false;
    }

    int num = abs(dividend);
    int den = abs(divisor);

    int ans = 0;
    while (num >= den) {
        int counter = 0;                            // begins with 2^0 as that WILL be possible

        while (num >= (den << (counter+1))) {       // den * (2^(counter+1)))
            counter++;
        }

        ans += (1 << counter);                      // (2^counter)
        num -= (den * (1 << counter));
    }
    
    if (ans >= INT_MAX && sign == true) {
        return INT_MAX;
    }
    if (ans >= INT_MAX && sign == false) {
        return INT_MIN;
    }

    return sign ? ans : (-1 * ans);
}

int main(){
    int dividend, divisor;
    cout << "Enter two numbers: ";
    cin >> dividend >> divisor;

    cout << "Value of " << dividend << " / " << divisor << " is: " << divide2Integers(dividend, divisor);
    return 0;
}