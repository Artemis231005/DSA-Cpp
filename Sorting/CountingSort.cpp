#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &arr) {
    if (arr.empty()) {
        return;
    }

    // Find minimum and maximum elements
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int num : arr) {
        if (num < minVal) {
            minVal = num;
        }
        if (num > maxVal) {
            maxVal = num;
        }
    }

    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    for (int num : arr) {
        count[num - minVal]++;
    }

    for (int i = 1; i < range; i++) {   // Cumulative freq
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());

    // Build the sorted array (traverse backwards to ensure stability/ensure in place)
    for (int i = arr.size() - 1; i >= 0; i--) {
        int num = arr[i];
        output[count[num - minVal] - 1] = num;
        count[num - minVal]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (can include negative numbers): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
