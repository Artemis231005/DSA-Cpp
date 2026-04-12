#include <iostream>
#include <cmath>
using namespace std;

int isArmstrong (int n) {
    int temp1 = n, temp2 = n;;
    int res = 0;
    int digits = 0;

    while (temp1 > 0) {
        digits++;
        temp1 /= 10;
    }
    while(temp2 > 0) {
        int lastDigit = temp2 % 10;
        temp2 /= 10;
        res += pow(lastDigit, digits); 
    }
    return n == res;
}

int main() {
    int no = 371;
    if (isArmstrong(no)) {
        cout << "Is an Armstrong Number";
    } else {
        cout << "Is not an Armstrong Number";
    }
    return 0;
}