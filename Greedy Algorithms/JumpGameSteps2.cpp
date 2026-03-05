#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC: O(n)   SC: O(1)
int minJumps(int noOfJumps, vector<int> &jumps) {
    int l = 0, r = 0;

    while (r < jumps.size()-1) {    // while loop is just to check if we reached end
        int farthest = 0;

        for (int i=l; i<=r; i++) {
            farthest = max(farthest, i + jumps[i]);
        }
        l = r + 1;
        r = farthest;
        noOfJumps++;
    }

    return noOfJumps;
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

    cout << "Minimum number of jumps are: " << minJumps(0, jumps) << endl;
    return 0;
}