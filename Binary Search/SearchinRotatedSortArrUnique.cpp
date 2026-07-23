#include <iostream>
#include <vector>
using namespace std;

// TC: O(log2 N)
int search(vector<int> &vec, int target) {
    int low = 0, high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            return mid;
        }
        
        // Identify whether left sorted or right sorted
        if (vec[low] <= vec[mid]) {                             // left sorted
            if (vec[low] <= target && target <= vec[mid]) {     // if target is in the sorted ie left half, eliminate right half
                high = mid - 1;
            } else {                                            // target doesn't lie in left half, so eliminate left half
                low = mid + 1;
            }
        } else {                                                // right sorted
            if (vec[mid] <= target && target <= vec[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
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

    cout << "Target found at: " << search(vec, target);
    return 0;
}