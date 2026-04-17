#include<iostream>
using namespace std;

void swap2Nos(int &a, int &b){
    a = a ^ b; 
    b = a ^ b;   // b = (a ^ b) ^ b = a
    a = a ^ b;   // a = (a ^ b) ^ a = b
}

int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout<<"Before swapping: " << endl;
    cout << "a: "<< a << " b: "<< b << endl;
    
    swap2Nos(a, b);
    cout<<"After swapping: " << endl;
    cout << "a: "<< a << " b: "<< b << endl;
    return 0;
}