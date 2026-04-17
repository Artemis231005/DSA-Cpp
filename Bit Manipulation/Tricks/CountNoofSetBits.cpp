#include<iostream>
using namespace std;

// TC: O(log2 N) max will be O(31) (for largest: 2^31)
int countNoofSetBits1 (int no){
    int counter = 0;

    while (no > 0) {
        counter += (no & 1);   // 1 if odd and 0 if even
        no = no >> 1;   // n = n / 2;
    }
    return counter;
}

// Brian Kernighan’s Algorithm (Optimized), slightly better approach as most nos wont have all bits as set
// TC: O(no of set bits) = O(32) for integer
int countNoofSetBits2 (int no){
    int counter = 0;

    while (no != 0) {
        no = no & (no - 1);   // removing last(rightmost) bit each time and calculating no of times to reach 0
        counter++;
    }

    return counter;
}

// or use built_in_popcount(n)
// __builtin_popcount(no);        // for int
// __builtin_popcountll(no);      // for long long

int main(){
    int no;
    cout << "Enter a number: ";
    cin >> no;
    
    cout << "No of set bits in " << no << " is: " << countNoofSetBits1(no);
    cout << "\nNo of set bits in " << no << " is: " << countNoofSetBits2(no);
    return 0;
}