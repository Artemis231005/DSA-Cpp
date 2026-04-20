#include<iostream>
using namespace std;

// TC: O(N)   SC: O(1)
int powerExponentiation(int n, int power) {
    int ans = 1;

    for (int i=0; i<power; i++) {
        ans = ans * n;
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