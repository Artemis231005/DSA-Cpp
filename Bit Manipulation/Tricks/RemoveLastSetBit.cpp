#include<iostream>
using namespace std;

int removeLastBit (int no){
    return no & (no - 1);
}

int main(){
    int no;
    cout << "Enter a number: ";
    cin >> no;
    
    cout << "Number after removing last set bit: " << removeLastBit(no);
    return 0;
}