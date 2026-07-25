#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

// TC: O(N) * O(log2 (max elem)) (binary search)
int getMaxElem(vector<int> &vec) {
    int maxElem = INT_MIN;

    for (int i=0; i<vec.size(); i++) {
        maxElem = max(maxElem, vec[i]);
    }
    return maxElem;
}

int calculateTotalHours(vector<int> &vec, int hourly) {
    int totalHrs = 0;

    for (int i=0; i<vec.size(); i++) {
        totalHrs += ceil((double)vec[i] / (double)hourly);
    }
    return totalHrs;
}

int minRateToEatBananas(vector<int> &vec, int h) {
    int low = 1, high = getMaxElem(vec);

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int totalHrs = calculateTotalHours(vec, mid);

        if (totalHrs <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, elem, h;
    vector<int> vec;
    cout << "Enter the number of piles of bananas: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    cout << "Enter the hours within which all bananas must be eaten: ";
    cin >> h;

    cout << "Minimum hourly rate is: " << minRateToEatBananas(vec, h);
    return 0;
}