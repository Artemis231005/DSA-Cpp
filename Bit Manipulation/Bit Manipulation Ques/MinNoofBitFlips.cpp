#include<iostream>
using namespace std;

int countNoofSetBits(int no){
    int counter = 0;

    while (no != 0) {
        no = no & (no - 1);   
        counter++;
    }

    return counter;
}

int minNoofBitFlipsToConvertNo(int start, int goal) {
    int temp = start ^ goal;
    return countNoofSetBits(temp);
}

int main(){
    int start, goal;
    cout << "Enter starting number: ";
    cin >> start;
    cout << "Enter goal number: ";
    cin >> goal;
    
    cout << "Minimum no of bit flips to convert " << start << " to " << goal << " is: " << minNoofBitFlipsToConvertNo(start, goal);
    return 0;
}