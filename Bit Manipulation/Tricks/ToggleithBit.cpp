#include<iostream>
using namespace std;

int toggleithBit (int no, int i){
    return no ^ (1 << i);
}

int main(){
    int no, i;
    cout << "Enter a number: ";
    cin >> no;
    cout << "Enter position to toggle: ";
    cin >> i;
    
    cout << "Number after toggling bit: " << toggleithBit(no, i);
    return 0;
}