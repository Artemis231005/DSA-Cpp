#include <iostream>
#include <vector>
using namespace std;

// TC: O(log N)   SC: O(1)
int iterativeBinarySearch(vector<int> vec, int target) {
    int low = vec[0];
    int high = vec[vec.size()-1];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            return mid;
        } else if (vec[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
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

    cout << "Target found at: " << iterativeBinarySearch(vec, target);
    return 0;
}