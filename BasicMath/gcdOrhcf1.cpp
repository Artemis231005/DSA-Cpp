#include<iostream>
using namespace std;

int gcdOrhcf(int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) {
            n1 = n1 % n2;
        } else {                                // else also handles n1 == n2 case
            n2 = n2 % n1;
        }
    }
    if (n1 == 0) {
        return n2;
    } else {
        return n1;
    }
}
// TC: O(logphi (min(n1, n2))) 

int main() {
    cout <<"Gcd or Hcf is: " <<  gcdOrhcf(20, 40);
    return 0;
}