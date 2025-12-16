#include<iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    print(arr, n);

    if (isSorted(arr, n)) {
        cout << "Sorted" << endl;
    } else {
        cout << "Not sorted" << endl;
    }
    return 0;
}