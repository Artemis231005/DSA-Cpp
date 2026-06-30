#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(log N)   SC: O(1)
int upperBound(vector<int> &vec, int target) {
    int low = 0;
    int high = vec.size()-1;
    int ans = vec.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] > target) {       // might be ans
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;              // go right to find larger elems
        }
    }

    return ans;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, elem, target;
    vector<int> vec;
    cout << "Enter number of elements of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    cout << "Enter target element: ";
    cin >> target;

    cout << "Upper bound of target using iteration found at: " << upperBound(vec, target) << endl;
    cout << "Upper bound of target using upper bound method found at: " << upper_bound(vec.begin(), vec.end(), target) - vec.begin();
    // upperr_bound(vec.begin(), vec.end(), target); return iterator pointing to the index
    // To get index, subtract vec.begin()
    return 0;
}