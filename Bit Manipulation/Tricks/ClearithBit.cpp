#include<iostream>
using namespace std;

int clearithBit (int no, int i){
    return no & ~(1 << i);
}

int main(){
    int no, i;
    cout << "Enter a number: ";
    cin >> no;
    cout << "Enter position to clear: ";
    cin >> i;
    
    cout << "Number after clearing bit: " << clearithBit(no, i);
    return 0;
}