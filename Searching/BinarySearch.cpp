#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int val) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == val) {
            return mid; 
        }
        else if (arr[mid] < val) {
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
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

    int result = binarySearch(arr, n, val);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in array." << endl;
    }

    return 0;
}
