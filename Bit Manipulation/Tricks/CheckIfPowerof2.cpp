#include<iostream>
using namespace std;

bool isPowerof2 (int no){
    return ((no & (no - 1)) == 0);
}

int main(){
    int no;
    cout << "Enter a number: ";
    cin >> no;
    
    if (isPowerof2(no)) {
        cout << "The number " << no << " is a power of 2";
    } else {
        cout << "The number " << no << " is not a power of 2";
    }
    return 0;
}