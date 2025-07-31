#include<iostream>
#include<cmath>
using namespace std;

void gcdOrhcf(int n1, int n2) {
    for (int i = min(n1, n2); i >= 0; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            cout << i;
            break;
        }
    }
}
// Worst Case (hcf: 1) TC: o(n)

int main() {
    cout <<"Gcd or Hcf is: ";
    gcdOrhcf(20, 40);
    return 0;
}