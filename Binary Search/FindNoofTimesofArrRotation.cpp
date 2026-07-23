#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinimum(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Array is already sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right half contains the minimum
        else {
            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

void findNoOfTimesofArrRotation(vector<int> &vec) {
    int n = vec.size();
    cout << "No of right rotations: " << findMinimum(vec) << endl;
    cout << "No of left rotations: " << (n - findMinimum(vec)) % n;
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

    findNoOfTimesofArrRotation(vec);
    return 0;
}