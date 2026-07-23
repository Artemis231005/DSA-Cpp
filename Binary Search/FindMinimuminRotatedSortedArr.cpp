#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int findMinimum(vector<int> vec) {
    int low = 0;
    int high = vec.size()-1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // arr is already sorted, hence vec[low] will always be smaller
        if (vec[low] <= vec[high]) {
            ans = min(ans, vec[low]);
            break;
        }

        if (vec[low] <= vec[mid]) {     // Left half is sorted
            ans = min(ans, vec[low]);
            low = mid + 1;
        } else {                        // Right half contains the pivot
            high = mid - 1;
            ans = min(ans, vec[mid]);
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

    cout << "Minimum is: " << findMinimum(vec);
    return 0;
}