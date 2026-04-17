#include<iostream>
using namespace std;

int setithBit (int no, int i){
    return no | (1 << i);
}

int main(){
    int no, i;
    cout << "Enter a number: ";
    cin >> no;
    cout << "Enter position to set: ";
    cin >> i;
    
    cout << "Number after setting bit: " << setithBit(no, i);
    return 0;
}