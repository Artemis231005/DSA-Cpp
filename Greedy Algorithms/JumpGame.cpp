#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC: O(n)   SC: O(1)
bool canReach(vector<int> &jumps) {
    int maxIdx = 0;
    for (int i=0; i<jumps.size(); i++) {
        if (i > maxIdx) {
            return false;
        }
        maxIdx = max(maxIdx, i + jumps[i]);

        if (maxIdx >= jumps.size() - 1) {
            break;
        }
    }
    return true;
}

int main() {
    int n, m, val;
    cout << "Enter number of steps: ";
    cin >> n;
    vector<int> jumps;

    cout << "Enter jumps: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        jumps.push_back(val);
    }

    if (canReach(jumps)) {
        cout << "Can reach end";
    }
    else {
        cout << "Cannot reach end";
    }
    return 0;
}