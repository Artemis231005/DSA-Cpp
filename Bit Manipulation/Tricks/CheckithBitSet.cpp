#include<iostream>
using namespace std;

void checkithBitSetLeftShift (int no, int i){
    int res = no & (1 << i);
    if (res != 0){
        cout << "Set bit";
    }
    else {
        cout << "Not set bit";
    }
}

void checkithBitSetRightShift (int no, int i){
    int res =  (no >> i) & 1;
    if (res != 0){
        cout << "Set bit";
    }
    else {
        cout << "Not set bit";
    }
}

int main(){
    int no, i;
    cout << "Enter a number: ";
    cin >> no;
    cout << "Enter position to check if bit is set or not: ";
    cin >> i;
    
    cout << "Checking ith bit using left shift operator: ";
    checkithBitSetLeftShift(no, i);

    cout << "\nChecking ith bit using right shift operator: ";
    checkithBitSetRightShift(no, i);
    return 0;
}