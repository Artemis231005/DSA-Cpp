#include <iostream>
#include <vector>
using namespace std;

// TC: O(log2 N) (for avg case)   Worst Case TC: O(N) (if lots of duplicates)
// Worst Case: O(N/2) approx as arr gets 2 elem removed at each iteratiion leading to neara bout n/2 iterations => O(N/2) => O(N)
int search(vector<int> &vec, int target) {
    int low = 0, high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            return mid;
        }
        
        if (vec[low] == vec[mid] && vec[mid] == vec[high]) {
            // Trim search space
            low ++;
            high --;
            continue;   // so next interation is the trimmed search space
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