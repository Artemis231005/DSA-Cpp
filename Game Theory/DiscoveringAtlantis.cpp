#include<iostream>
#include<vector>
#include<climits>
using namespace std;

string remainInCharge(int N) {
    if (N % 3 == 0) {
        return "JACK";
    } else {
        return "JELLY";
    }
}

int main() {
    int N;
    cout << "Enter ending distance (start = 0): ";
    cin >> N;

    cout << "Person in charge when reaching Atlantis: " << remainInCharge(N);
    return 0;
}