#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// TC: O(n^n)   SC: O(n)
int minJumps(int idx, int noOfJumps, vector<int> &jumps) {
    if (idx >= jumps.size() - 1) {
        return noOfJumps;
    }
    int minNo = INT_MAX;

    for (int i = 1; i <= jumps[idx]; i++) {
        minNo = min(minNo, minJumps(idx + i, noOfJumps + 1, jumps));
    }
    return minNo;
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

    cout << "Minimum number of jumps are: " << minJumps(0, 0, jumps) << endl;
    return 0;
}