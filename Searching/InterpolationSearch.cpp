#include <iostream>
using namespace std;

// Interpolation Search works best when elements are sorted and uniformly distributed

int interpolationSearch(int arr[], int n, int val) {
    int low = 0;
    int high = n - 1;

    while (low <= high && val >= arr[low] && val <= arr[high]) {
        if (low == high) {
            if (arr[low] == val) {
                return low;
            }
            return -1;
        }

        // Interpolation pos formula
        int pos = low + ((high - low) / (arr[high] - arr[low])) * (val - arr[low]);

        if (arr[pos] == val) {
            return pos; 
        }
        else if (arr[pos] < val) {
            low = pos + 1;
        }
        else {
            high = pos - 1; 
        }
    }

    return -1; // not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int val;
    cout << "Enter element to search: ";
    cin >> val;

    int result = interpolationSearch(arr, n, val);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in array." << endl;
    }

    return 0;
}
