#include<iostream>
#include<vector>
#include<climits>
using namespace std;

string arrayGame(vector<int> vec, int n) {
    // find max elem
    int maxElem = INT_MIN;
    for (int i=0; i<n; i++) {
        if (vec[i] > maxElem) {
            maxElem = vec[i];
        }
    }

    int diff = 0;           // no of moves left to reach terminal state
    for (int i=0; i<n; i++) {
        diff += maxElem - vec[i];
    }

    if (diff == 0) {        // means arr given to us was already equal -> Draw
        return "Draw!";
    }

    if (diff & 1) {         // if diff is odd -> means first player will win
        return "First Player wins!";
    } else {
        return "Second Player wins!";
    }

    return "Invalid!";
}

int main() {
    int n, val;
    cout << "Enter size: ";
    cin >> n;

    vector<int> vec;
    cout << "Enter elements: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "The outcome of the array game is: " << arrayGame(vec, n);
    return 0;
}